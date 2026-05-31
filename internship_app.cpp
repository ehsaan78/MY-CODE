#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <winhttp.h>

using namespace std;

struct Internship {
    string title;
    string company;
    string location;
    string url;
    bool online;
};

string toLower(const string &value) {
    string result = value;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

bool containsIgnoreCase(const string &text, const string &query) {
    return toLower(text).find(toLower(query)) != string::npos;
}

string httpGet(const wstring &host, const wstring &path) {
    string response;
    HINTERNET hSession = WinHttpOpen(L"Internship Finder/1.0",
                                     WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
                                     WINHTTP_NO_PROXY_NAME,
                                     WINHTTP_NO_PROXY_BYPASS,
                                     0);
    if (!hSession) return response;

    HINTERNET hConnect = WinHttpConnect(hSession, host.c_str(), INTERNET_DEFAULT_HTTPS_PORT, 0);
    if (!hConnect) {
        WinHttpCloseHandle(hSession);
        return response;
    }

    HINTERNET hRequest = WinHttpOpenRequest(hConnect,
                                           L"GET",
                                           path.c_str(),
                                           NULL,
                                           WINHTTP_NO_REFERER,
                                           WINHTTP_DEFAULT_ACCEPT_TYPES,
                                           WINHTTP_FLAG_SECURE);
    if (!hRequest) {
        WinHttpCloseHandle(hConnect);
        WinHttpCloseHandle(hSession);
        return response;
    }

    if (!WinHttpSendRequest(hRequest,
                            WINHTTP_NO_ADDITIONAL_HEADERS,
                            0,
                            WINHTTP_NO_REQUEST_DATA,
                            0,
                            0,
                            0) ||
        !WinHttpReceiveResponse(hRequest, NULL)) {
        WinHttpCloseHandle(hRequest);
        WinHttpCloseHandle(hConnect);
        WinHttpCloseHandle(hSession);
        return response;
    }

    DWORD bytesAvailable = 0;
    while (WinHttpQueryDataAvailable(hRequest, &bytesAvailable) && bytesAvailable > 0) {
        vector<char> buffer(bytesAvailable + 1);
        DWORD bytesRead = 0;
        if (!WinHttpReadData(hRequest, buffer.data(), bytesAvailable, &bytesRead)) {
            break;
        }
        response.append(buffer.data(), bytesRead);
    }

    WinHttpCloseHandle(hRequest);
    WinHttpCloseHandle(hConnect);
    WinHttpCloseHandle(hSession);
    return response;
}

string extractJsonString(const string &json, size_t startPos) {
    size_t quoteStart = json.find('"', startPos);
    if (quoteStart == string::npos) return "";
    string value;
    bool escape = false;
    for (size_t i = quoteStart + 1; i < json.size(); ++i) {
        char c = json[i];
        if (escape) {
            value += c;
            escape = false;
        } else if (c == '\\') {
            escape = true;
        } else if (c == '"') {
            return value;
        } else {
            value += c;
        }
    }
    return "";
}

string getJsonField(const string &json, const string &field, size_t start, size_t end) {
    string key = '"' + field + '"';
    size_t pos = json.find(key, start);
    if (pos == string::npos || pos >= end) return "";
    pos = json.find(':', pos + key.length());
    if (pos == string::npos || pos >= end) return "";
    return extractJsonString(json, pos + 1);
}

vector<Internship> parseRemoteJobs(const string &json) {
    vector<Internship> jobs;
    size_t pos = 0;
    while ((pos = json.find("\"title\"", pos)) != string::npos) {
        size_t objBegin = json.rfind('{', pos);
        size_t objEnd = json.find('}', pos);
        if (objBegin == string::npos || objEnd == string::npos) break;

        string title = getJsonField(json, "title", objBegin, objEnd);
        string company = getJsonField(json, "company_name", objBegin, objEnd);
        string location = getJsonField(json, "candidate_required_location", objBegin, objEnd);
        string url = getJsonField(json, "url", objBegin, objEnd);

        if (!title.empty()) {
            if (location.empty()) location = "Worldwide";
            jobs.push_back({title, company, location, url, true});
        }
        pos = objEnd + 1;
    }
    return jobs;
}

vector<Internship> filterLocal(const vector<Internship> &localJobs, const string &locality) {
    vector<Internship> filtered;
    for (const auto &job : localJobs) {
        if (containsIgnoreCase(job.location, locality)) {
            filtered.push_back(job);
        }
    }
    return filtered;
}

vector<Internship> filterOnline(const vector<Internship> &jobs, const string &locality) {
    vector<Internship> filtered;
    for (const auto &job : jobs) {
        if (containsIgnoreCase(job.location, "worldwide") ||
            containsIgnoreCase(job.location, "remote") ||
            containsIgnoreCase(job.location, locality)) {
            filtered.push_back(job);
        }
    }
    return filtered;
}

void showInternships(const vector<Internship> &items, const string &header) {
    cout << header << "\n";
    if (items.empty()) {
        cout << "No internships found.\n";
        return;
    }
    for (size_t i = 0; i < items.size(); ++i) {
        const auto &intern = items[i];
        cout << "\n" << (i + 1) << ". " << intern.title << "\n";
        cout << "   Company: " << intern.company << "\n";
        cout << "   Location: " << intern.location << "\n";
        if (!intern.url.empty()) cout << "   Apply: " << intern.url << "\n";
        cout << "   Mode: " << (intern.online ? "Online" : "Offline") << "\n";
    }
}

int main() {
    vector<Internship> localInternships = {
        {"Marketing Intern", "Local Media Co.", "Srinagar", "", false},
        {"Web Development Intern", "Tech Local Pvt Ltd", "Srinagar", "", false},
        {"Graphic Design Intern", "Creative Studio", "Anantnag", "", false},
        {"IT Support Intern", "City Services", "Baramulla", "", false},
        {"Content Intern", "Edu Writes", "Srinagar", "", false}
    };

    cout << "=== Internship Finder (Online + Local) ===\n";
    cout << "Enter your city/locality: ";
    string locality;
    getline(cin, locality);

    cout << "Choose mode (offline / online / both): ";
    string mode;
    getline(cin, mode);
    mode = toLower(mode);

    if (mode != "offline" && mode != "online" && mode != "both") {
        cout << "Invalid mode. Use offline, online, or both.\n";
        return 0;
    }

    if (mode == "offline" || mode == "both") {
        vector<Internship> localResults = filterLocal(localInternships, locality);
        showInternships(localResults, "\n--- Offline internships in your locality ---");
    }

    if (mode == "online" || mode == "both") {
        cout << "\n--- Fetching online internships from the web ---\n";
        string response = httpGet(L"remotive.com", L"/api/remote-jobs?search=internship");
        if (response.empty()) {
            cout << "Unable to fetch online results. Check your internet connection.\n";
            return 0;
        }
        vector<Internship> onlineJobs = parseRemoteJobs(response);
        vector<Internship> onlineResults = filterOnline(onlineJobs, locality);
        showInternships(onlineResults, "\n--- Online internships ---");
    }

    return 0;
}

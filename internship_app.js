const https = require('https');
const readline = require('readline');

const localInternships = [
  { title: 'Marketing Intern', company: 'Local Media Co.', location: 'Srinagar' },
  { title: 'Web Development Intern', company: 'Tech Local Pvt Ltd', location: 'Srinagar' },
  { title: 'Graphic Design Intern', company: 'Creative Studio', location: 'Anantnag' },
  { title: 'IT Support Intern', company: 'City Services', location: 'Baramulla' },
  { title: 'Content Intern', company: 'Edu Writes', location: 'Srinagar' }
];

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

function ask(question) {
  return new Promise(resolve => rl.question(question, answer => resolve(answer.trim())));
}

function fetchRemoteInternships(search = 'internship') {
  const url = `https://remotive.com/api/remote-jobs?search=${encodeURIComponent(search)}`;

  return new Promise((resolve, reject) => {
    https.get(url, response => {
      let body = '';
      response.on('data', chunk => body += chunk);
      response.on('end', () => {
        try {
          const data = JSON.parse(body);
          if (!Array.isArray(data.jobs)) {
            return reject(new Error('Unexpected API response'));
          }
          resolve(data.jobs);
        } catch (error) {
          reject(error);
        }
      });
    }).on('error', reject);
  });
}

function showInternships(items) {
  if (items.length === 0) {
    console.log('No internships found for the selected search.');
    return;
  }

  items.forEach((item, index) => {
    console.log(`\n${index + 1}. ${item.title}`);
    console.log(`   Company: ${item.company}`);
    console.log(`   Location: ${item.location}`);
    if (item.url) console.log(`   Apply: ${item.url}`);
  });
}

function filterLocal(locality) {
  const search = locality.toLowerCase();
  return localInternships.filter(item => item.location.toLowerCase().includes(search));
}

function filterOnline(jobs, locality) {
  const search = locality.toLowerCase();
  return jobs
    .filter(job => /intern/i.test(job.title) || /intern/i.test(job.category || ''))
    .map(job => ({
      title: job.title,
      company: job.company_name,
      location: job.candidate_required_location || 'Worldwide',
      url: job.url
    }))
    .filter(job => {
      if (job.location.toLowerCase().includes('worldwide')) return true;
      if (job.location.toLowerCase().includes('remote')) return true;
      return job.location.toLowerCase().includes(search);
    });
}

async function main() {
  try {
    console.log('=== Internship Finder (Internet Enabled) ===');
    const locality = await ask('Enter your city/locality: ');
    let mode = await ask('Choose mode (offline / online / both): ');
    mode = mode.toLowerCase();

    const wantOffline = mode === 'offline' || mode === 'both';
    const wantOnline = mode === 'online' || mode === 'both';

    if (!['offline', 'online', 'both'].includes(mode)) {
      console.log('Invalid mode. Use "offline", "online", or "both".');
      rl.close();
      return;
    }

    if (wantOffline) {
      console.log('\n--- Offline internships in your locality ---');
      const localResults = filterLocal(locality);
      showInternships(localResults);
    }

    if (wantOnline) {
      console.log('\n--- Fetching online internships from the web ---');
      const jobs = await fetchRemoteInternships('internship');
      const onlineResults = filterOnline(jobs, locality);
      showInternships(onlineResults.slice(0, 15));
    }
  } catch (error) {
    console.log('Error fetching online internships:', error.message);
  } finally {
    rl.close();
  }
}

main();

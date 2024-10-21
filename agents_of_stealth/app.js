const express = require('express');
const app = express();
app.use(express.static('public'));

app.get('/', (req, res) => {    
    res.sendFile(__dirname + '/public/index.html');
});

app.get('/robots.txt', (req, res) => {
    res.type('text/plain');
    res.send("User-agent: *\nDisallow: /agent/monkey");
});

app.get('/agent/monkey', (req, res) => {
    const userAgent = req.get('User-Agent');
    
    // Block requests from browsers
    if (/chrome|firefox|safari|edge|opera/i.test(userAgent)) {
        res.status(403).send("Access Denied: This mission requires something less obvious. Agents always know the right tools for the job.");
    } else {
        // Send the flag for non-browser requests
        res.send('CaptureTheHeadsCTF{n0_m0nk3y_8u5in355_ju57_c13v3rn355}');
    }
});
app.listen(5000, () => {
    console.log('Listening on port 5000!');
});

## Question : 
The web is crawling with bugs and they don't like flashy visitors. Sometimes, you need to take a quieter approach to sneak past them and catch what's hidden.

Deployed at : https://apectf-2-0-questions.onrender.com

## Solution : 


### The Hint – Crawling

The word "crawling" in the problem statement should give you a clue that this is related to web crawlers and indexing.

Websites often use a `robots.txt` file to specify paths that should or shouldn’t be accessed by crawlers.

### Accessing `robots.txt`

Navigate to: <website-domain-name>/robots.txt

This will reveal the hidden path: `/agent/monkey`.

### Accessing the Hidden Path

When you try to access `/agent/monkey` through your browser, you’ll encounter the following message:

> "Access Denied: This mission requires something less obvious. Agents always know the right tools for the job."

### Another hint

The phrases *"quieter approach"* from the problem statement and *"right tools"* from the browser message hint that you need to use a non-browser method, like `curl`, to access the path.

### Curling the Path

When you use `curl` to access the same path, you will successfully retrieve the flag.

### Explanation Behind curl :

- Our server checks the `User-Agent` header in the request.
- Modern browsers, by default, include their name in this header (e.g., "Chrome", "Firefox", "Safari").
- `curl`, on the other hand, leaves this header (and many others) empty by default.
- The backend checks the `User-Agent` header, and if it contains any well-known browsers, it will respond with *"Access Denied."*
- Since `curl` sends the request without the browser's user-agent, the server grants access and returns the flag.

---

### Example Curl Command:

```bash
curl -A "" http://<website-domain-name>/agent/monkey
```


## Tools : 
- Curl

## Final Answer
- CaptureTheHeadsCTF{n0_m0nk3y_8u5in355_ju57_c13v3rn355}

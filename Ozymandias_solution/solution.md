### Ozymandias

 Inspiration - "Time erodes all, even the strongest walls."
 
 And so, given a wise input, that takes too long, the flag shall present itself to thee.
 
## Logic

Basically leaving the shit things in the code, we need to focus that there is an insertion taking place unordered_map.
The thing is that hashmap takes O(1) in general, which is what the knowledge of most people is aquainted to.
Under the hood, if somehow we can break the hash function, we can make this insertion complexity to O(n).

This blog explains in detail as to how : https://codeforces.com/blog/entry/62393

### Primes

So basically we need to take that list of primes and try numbers from it.
This can be done using a simple python script. I have done it using the pwntools library.

The code can be found in script.py

### Additional things 

The time constraint for 5 second is actually taken after a bit of experimenting.
On my system the code actually broke at the prime number : 42043

But when i ran it on my free t2.mircro ec2 instance, then it break much before at just 20753.
But nonetheless, since it works and is just as random to an ignorant solver, i went ahead with 5 seconds.

Also I put the sleep(1) in the processInput() function to prevent people to just brute it using a simple for loop from 1 to 1e6.

There is also a Anti dos signal in place, which prevents any kind of dos attack by closing connections which have neem inactive for a while.

### Scripting

So all that is left to do now is to get that list of primes from one of the links provided in the blog above.

We use the pwntools library for establishing the connectiion with the remote and to brute the entry of numbers from the list. Below is the code (can also be found in script.py file) : 

```python
    from pwn import *

# List of primes to test
'''
prime_list = [
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73,
    79, 83, 89, 97, 103, 109, 113, 127, 137, 139, 149, 157, 167, 179, 193, 199, 211,
    227, 241, 257, 277, 293, 313, 337, 359, 383, 409, 439, 467, 503, 541, 577, 619,
    661, 709, 761, 823, 887, 953, 1031, 1109, 1193, 1289, 1381, 1493, 1613, 1741,
    1879, 2029, 2179, 2357, 2549, 2753, 2971, 3209, 3469, 3739, 4027, 4349, 4703,
    5087, 5503, 5953, 6427, 6949, 7517, 8123, 8783, 9497, 10273, 11113, 12011,
    12983, 14033, 15173, 16411, 17749, 19183, 20753, 22447, 24281, 26267, 28411,
    30727, 33223, 35933, 38873, 42043, 45481, 49201, 53201, 57557, 62233, 67307,
    72817, 78779, 85229, 92203, 99733, 107897, 116731, 126271, 136607, 147793,
    159871, 172933, 187091, 202409, 218971, 236897, 256279, 277261, 299951, 324503,
    351061, 379787, 410857, 444487, 480881, 520241, 562841, 608903, 658753, 712697,
    771049, 834181, 902483, 976369
]
'''
prime_list = [2971, 3209, 3469, 3739, 4027, 4349, 4703,
    5087, 5503, 5953, 6427, 6949, 7517, 8123, 8783, 9497, 10273, 11113, 12011,
    12983, 14033, 15173, 16411, 17749, 19183,
     20753, 22447, 24281, 26267, 28411,
    30727, 33223, 35933, 38873, 42043, 45481, 49201, 53201, 57557, 62233, 67307,
    72817, 78779, 85229, 92203, 99733, 107897, 116731, 126271, 136607, 147793,
    159871, 172933, 187091, 202409, 218971, 236897, 256279, 277261, 299951, 324503,
    351061, 379787, 410857, 444487, 480881, 520241, 562841, 608903, 658753, 712697,
    771049, 834181, 902483, 976369
]

# Connect to the remote server
#host = "127.0.0.1" 
host = "3.110.104.119" # gotta change the ip here accordingly
port = 5184

def main():
    for prime in prime_list:
        # Send the prime number to the program
        conn = remote(host, port)
        
        conn.sendline(str(prime).encode())
        

        result = conn.recvline()
        
        print(prime, result)
        
        conn.close()

        # Check if output contains the flag
        if b'capturetheheadsctf' in result.lower():
            print(f"Found valid input: {prime}")
            print(result)
            break

if __name__ == "__main__":
    main()


```
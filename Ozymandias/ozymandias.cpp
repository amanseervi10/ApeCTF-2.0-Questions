#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;
int time_taken = 0;

void kill_on_timeout(int sig) {
  if (sig == SIGALRM) {
  	printf("[!] Anti DoS Signal.\n");
  	fflush(stdout);
    _exit(0);
  }
}

void init_signal() {
	signal(SIGALRM, kill_on_timeout);
	alarm(60);
}

double blackMagic(int input) {
    long long result = 0;
    for (int i=1; i<=10000; i++) {
        result += input ^ (i*i);
        result = result % (int)(1e9 + 7);
    }
    return result*1.0/(int)(1e9+7);
}

int processInput(long long factor) {
    clock_t start = clock();
    unordered_map<long long, int> dataMap;
    long long cumulative = 0;

    for (int i=1; i<=N; i++) {
        int base = (i+3)*2;

        if (i%666 == 0) {
            double result = blackMagic(base);

            if (result<0.5) base+= i%10;
        }

        dataMap[i*factor] = base;
    }

    for (auto &entry: dataMap) {
        entry.second ^= (entry.second << 2) | (entry.second >> 1);
        cumulative += entry.second;
        if (cumulative > 10000) {
            cumulative = cumulative - (16384 >> 2);
            break;
        }
    }

    time_taken = (double)(clock() - start)/CLOCKS_PER_SEC;
    
    sleep(1);

    return cumulative;
}

int main() {
    init_signal();
  
    printf("Enter a number: ");
    fflush(stdout);
    int k; 
    scanf("%d", &k);

    if (k > 1000000) {
        printf("Nigga too much!!\n");
    } else {
        int value_generated = processInput(k);

        if (value_generated == 14588 || time_taken > 5) {
            ifstream flagFile("flag.txt");
            if (flagFile.is_open()) {
                string flag;
                getline(flagFile, flag);
                printf("%s\n", flag.c_str());
                flagFile.close();
            } else {
                printf("Could not open the flag file!\n");
            }
        } else {
            printf("Not quite right...\n");
        }
    }
    
    return 0;
}

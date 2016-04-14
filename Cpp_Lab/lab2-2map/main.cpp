#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <string>
using namespace std;

char s[1000001];

int main() {
    int N;
    map<string, int> cont;
    
    while (scanf("%d%s",&N,s) == 2) {
        int L = strlen(s);
        cont.clear();
        
        for (int i=0; i+N<=L; ++i) {
			char tmp[1000001];
            strcpy(tmp, s);
			tmp[N + i] = 0;
            cont[tmp + i]++;
        }
        
        string ans_hash;
        int best = -1;
        
        for (map<string, int>::iterator it=cont.begin(); it!=cont.end(); ++it) {
            if (it->second > best) {
                ans_hash = it->first;
                best = it->second;
            }
        }
        
        printf("%s:%d\n", ans_hash.c_str(), best);
    }
    
    return 0;
}
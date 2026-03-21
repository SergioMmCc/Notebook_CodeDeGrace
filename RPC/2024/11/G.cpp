#include<bits/stdc++.h>
using namespace std;
#define endl '\n'



map<string, int> heros;

void fildMap() {
    heros["Shadow"] = 6;
    heros["Gale"] = 5;
    heros["Ranger"] = 4;
    heros["Anvil"] = 7;
    heros["Vexia"] = 3;
    heros["Guardian"] = 8;
    heros["Thunderheart"] = 6;
    heros["Frostwhisper"] = 2;
    heros["Voidclaw"] = 3;
    heros["Ironwood"] = 3;
    heros["Zenith"] = 4;
    heros["Seraphina"] = 1;
}


int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);

    fildMap();

    int n = 3; 
    long long tiebreakA = 0, tiebreakB = 0; 
    int Awins = 0; 
    int Bwins = 0; 
    while(n--) {

        //First
        int a, totalA = 0; 
        cin >> a; 
        string aux; 


        for(int i=0; i<a; i++) {
            cin >> aux; 
            totalA += heros[aux]; 

            if(aux == "Seraphina") {
                totalA += a-1; 
            }

            if(aux == "Thunderheart" && a == 4) {
                totalA += heros["Thunderheart"];
            }

            if(aux == "Zenith" && n == 1) {
                totalA += 5; 
            }
        }
        tiebreakA += totalA; 


        //second
        int b, totalB = 0; 
        cin >> b; 

        for(int i=0; i<b; i++) {
            cin >> aux; 
            totalB += heros[aux]; 

            if(aux == "Seraphina") {
                totalB += b-1; 
            }

            if(aux == "Thunderheart" && b == 4) {
                totalB += heros["Thunderheart"];
            }

            if(aux == "Zenith" && n == 1) {
                totalB += 5; 
            }
        }
        tiebreakB += totalB; 

        if(totalA == totalB) continue; 

        if(totalA > totalB) {
            Awins++; 
            continue;
        }

        Bwins++; 
    }

    if(Awins == Bwins) {
        if(tiebreakA == tiebreakB) {
            cout << "Tie" << endl;
            return 0;
        }

        if(tiebreakA > tiebreakB) {
            cout << "Player 1" << endl; 
            return 0;
        }

        cout << "Player 2" << endl; 
        return 0; 
    }

    if(Awins > Bwins) {
        cout << "Player 1" << endl; 
        return 0;
    }

    cout << "Player 2" << endl; 
    return 0;

}
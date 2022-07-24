#include <stdio.h>
#include <stdbool.h>
#include <sstream>
#include <string.h>
#include <iostream>
#include <istream>
#include <time.h>
#include <string>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>
#include <chrono>

/* Author by : Nyoman Krisna Prebawa
*/
using namespace std;
#define inf 9999


int n;
int table[100][100];

int dijkstra(int mulai, int akhir){
    int dist[n];
    bool visited [n];
    int i,j,v;
    //Inisialisasi dari visited [x]=infinity
    for(i = 1;i <= n;i++){
        dist[i] = inf;
    }
    
    //Inisialisasi dari visited [x]=false
    for(i = 1; i <= n; i++){
        visited[i]= false;
    }

    dist[mulai]=0;
    while (true) //perulangan ini akan di akhiri dengan break
    {
        int u = -1;
        int minDist = inf;
        //mencari mode-mode yang belum dikunjungi 
        //dan memiliki dist terkecil
        for (i = 1; i <= n; i++)
        {
            if((visited[i]==false)&&(dist[i]<minDist)){
                u=i;
                minDist = dist[i];
            }
        }

        //untuk mengakhiri perulangan while
        if((u == -1)||(dist[u] == inf)){
            break;
        }
        visited[u] = true;

        //melakukan relax untuk semua tetangga u
        for (v = 1; v <= n; v++){
            if(table[u][v] != 0){
                if (dist[v] > dist[u] + table[u][v]){
                    dist[v] = dist[u] + table[u][v];
                }
            }
        }
    }
    return dist[akhir];
}

int main(){

    int mulai,akhir,i,j;
    cout << "masukkan banyak node : ";
    cin >> n;
    cout << "masukkan jarak node secara matriks : \n";
    for (i = 1; i <= n; i++)
    {
        for(j = 1;j <= n; j++){
            cin >> table[i][j];
        }
    }
    int jawab = 0,x;
    //menggunakan pengulangan agar bisa di test berulangkaliii bosss
    while (jawab == 0)
    {
        cout << "masukkan node start (awal) : ";
        cin >> mulai;
        cout << "masukkan node finish (akhir) : ";
        cin >> akhir;
        cout << ("jarak minimal dari node ", dijkstra(mulai,akhir)) << endl;
    }
    
    

}

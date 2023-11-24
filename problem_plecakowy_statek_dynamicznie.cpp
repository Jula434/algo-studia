#include <bits/stdc++.h>
using namespace std;

int optimal(vector<int>& weights, vector<int>& val, int shipcap) //f zwracajaca opt wart statku
{
    int n = weights.size();

    vector<vector<int>> k(n + 1, vector<int>(shipcap + 1, 0)); //wyniki

    for (int i = 1; i <= n; i++) //wypelnianie tab
        {
        for (int j = 1; j <= shipcap; j++)
        {
            if (weights[i - 1] <= j) //czy moze byc zaladowany
            {
                k[i][j] = max(val[i - 1] + k[i - 1][j - weights[i - 1]], k[i - 1][j]); //best
            }
            else
            {
                k[i][j] = k[i - 1][j];
            }
        }
    }

    return k[n][shipcap];
}

int main()
{
    int shipcap;
    int n;
    cout << "ladownosc statku: ";
    cin >> shipcap;
    cout << "liczba kontenerow: ";
    cin >> n;

    vector<int> weights(n);
    vector<int> val(n);

    for (int i = 0; i < n; i++)
    {
        cout << "waga i wartosc kontenera: " << i + 1 << ": ";
        cin >> weights[i] >> val[i];
    }

    int best = optimal(weights, val, shipcap);
    cout << best << endl; //optymalna wartosc ladunku

    return 0;
}


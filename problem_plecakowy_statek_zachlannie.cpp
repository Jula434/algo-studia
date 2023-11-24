#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int>& c1, pair<int, int>& c2)
{
    double temp1 = static_cast<double>(c1.second) / c1.first;
    double temp2 = static_cast<double>(c2.second) / c2.first;
    return temp1 > temp2;
}

int optimal(vector<int>& weights, vector<int>& val, int shipcap)
{
    int n = weights.size();

    vector<pair<int, int>> containers;
    for (int i = 0; i < n; i++)
    {
        containers.push_back(make_pair(weights[i], val[i]));
    }

    sort(containers.begin(), containers.end(), compare);

    int totalval = 0;
    int currweight = 0;

    for (auto container : containers)
    {
        if (currweight + container.first <= shipcap)
        {
            totalval += container.second;
            currweight += container.first;
        }
        else
        {
            break;
        }
    }

    return totalval;
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

    for (int i = 0; i < n; i++) {
        cout << "waga i wartosc kontenera " << i + 1 << ": ";
        cin >> weights[i] >> val[i];
    }

    int best = optimal(weights, val, shipcap);
    cout << best << endl; //optymalna wartosc ladunku

    return 0;
}

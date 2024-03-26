/**
 * https://og7kl7g6h8.feishu.cn/docx/EIEjdKhddoy5ePxqG1TcGnytneh
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    int distance;
    cin >> distance;
    int n;
    cin >> n;
    auto stations = vector<pair<int, int>>(n);
    for (int i = 0; i < n; i++)
    {
        cin >> stations[i].first >> stations[i].second;
        stations[i].second++;
    }

    auto min_time = vector<int>(n, INT_MAX);

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j >= 0; j--)
        {
            int &distance_i = stations[i].first, &distance_j = stations[j].first;
            int &cost = stations[i].second;
            if (distance_i - distance_j > 1000)
            {
                break;
            }
            else
            {
                min_time[i] = min(min_time[i], min_time[j] + cost);
            }
        }
    }

    int ans = min_time[n - 1] + distance / 100;
}
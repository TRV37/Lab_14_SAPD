#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;

// ������� ���������� ���������� ��� �������� ������ ����� ����������
unordered_map<string, vector<string>> adj;

// ������� BFS ��� ������ ����������� ���� �� ���������� �������� �� ���� ���������
unordered_map<string, int> BFS(string start)
{
    queue<string> q; // ������� ��� �������� ������ �����
    unordered_map<string, int> dist; // ������� ��� �������� ���������� �� ��������� ������� �� ���� ���������
    unordered_map<string, bool> visited; // ������� ��� ������������ ���������� ������

    // ������������� ��������� �������
    q.push(start);
    visited[start] = true;
    dist[start] = 0;

    // �������� ���� BFS
    while (!q.empty())
    {
        string node = q.front(); // ��������� ������� �� �������
        q.pop();

        // ���������� ��� �������� �������
        for (string neighbour : adj[node])
            // ���� ������� ��� �� ���� ��������
            if (!visited[neighbour])
            {
                q.push(neighbour); // ��������� ������� � �������
                visited[neighbour] = true; // �������� ������� ��� ����������
                dist[neighbour] = dist[node] + 1; // ��������� ���������� �� �������
            }

    }

    // ���������� ���������� �� ��������� ������� �� ���� ���������
    return dist;
}

int main() {
    // ��������� ����� ����� ����������
    adj["Azur"] = { "Intercosmos-Copernicus-500", "Explorer-1" };
    adj["Intercosmos-Copernicus-500"] = { "Azur", "Ariel 1" };
    adj["Explorer-1"] = { "Azur" };
    adj["Ariel 1"] = { "Intercosmos-Copernicus-500" };

    string start = "Azur"; // �������� ��������� �������

    // ��������� BFS �� ���������� ��������
    unordered_map<string, int> dist = BFS(start);

    // ������� ���������� ���������� �� ���������� �������� �� ���� ���������
    vector<string> names = { "Azur", "Intercosmos-Copernicus-500", "Explorer-1", "Ariel 1" };
    for (string name : names) {
        if (dist.count(name) == 0)
            cout << "There is no path from  " << start << " to " << name << endl;
        else
            cout << "The shortest distance from " << start << " to " << name << " is " << dist[name] << endl;
    }

    return 0;
}

//#include <iostream>
//#include <vector>
//#include <queue>
//#include <string>
//
//using namespace std;
//
//// ������� ���������� ���������� ��� �������� ������ ����� ����������
//vector<vector<int>> adj(4);
//
//// ������� BFS ��� ������ ����������� ���� �� ���������� �������� �� ���� ���������
//vector<int> BFS(int start)
//{
//    queue<int> q; // ������� ��� �������� ������ �����
//    vector<int> dist(4, -1); // ������ ��� �������� ���������� �� ��������� ������� �� ���� ���������
//
//    // ������������� ��������� �������
//    q.push(start);
//    dist[start] = 0;
//
//    // �������� ���� BFS
//    while (!q.empty())
//    {
//        int node = q.front(); // ��������� ������� �� �������
//        q.pop();
//
//        // ���������� ��� �������� �������
//        for (int neighbour : adj[node])
//            // ���� ������� ��� �� ���� ��������
//            if (dist[neighbour] == -1)
//            {
//                q.push(neighbour); // ��������� ������� � �������
//                dist[neighbour] = dist[node] + 1; // ��������� ���������� �� �������
//            }
//
//    }
//
//    // ���������� ���������� �� ��������� ������� �� ���� ���������
//    return dist;
//}
//
//int main() {
//    // ��������� ����� ����� ����������
//    adj[0] = { 1, 2 }; // Azur
//    adj[1] = { 0, 3 }; // Intercosmos-Copernicus-500
//    adj[2] = { 0 }; // Explorer-1
//    adj[3] = { 1 }; // Ariel 1
//
//    int start = 0; // �������� ��������� ������� (Azur)
//
//    // ��������� BFS �� ���������� ��������
//    vector<int> dist = BFS(start);
//
//    // ������� ���������� ���������� �� ���������� �������� �� ���� ���������
//    vector<string> names = { "Azur", "Intercosmos-Copernicus-500", "Explorer-1", "Ariel 1" };
//    for (int i = 0; i < dist.size(); ++i) {
//        if (dist[i] == -1)
//            cout << "There is no path from  " << names[start] << " to " << names[i] << endl;
//        else
//            cout << "The shortest distance from " << names[start] << " to " << names[i] << " is " << dist[i] << endl;
//    }
//
//    return 0;
//}
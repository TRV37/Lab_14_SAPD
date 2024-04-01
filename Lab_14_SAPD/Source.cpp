#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;

// Создаем глобальную переменную для хранения связей между спутниками
unordered_map<string, vector<string>> adj;

// Функция BFS для поиска кратчайшего пути от начального спутника до всех остальных
unordered_map<string, int> BFS(string start)
{
    queue<string> q; // очередь для хранения вершин графа
    unordered_map<string, int> dist; // словарь для хранения расстояний от начальной вершины до всех остальных
    unordered_map<string, bool> visited; // словарь для отслеживания посещенных вершин

    // Инициализация начальной вершины
    q.push(start);
    visited[start] = true;
    dist[start] = 0;

    // Основной цикл BFS
    while (!q.empty())
    {
        string node = q.front(); // извлекаем вершину из очереди
        q.pop();

        // Перебираем все соседние вершины
        for (string neighbour : adj[node])
            // Если вершина еще не была посещена
            if (!visited[neighbour])
            {
                q.push(neighbour); // добавляем вершину в очередь
                visited[neighbour] = true; // помечаем вершину как посещенную
                dist[neighbour] = dist[node] + 1; // обновляем расстояние до вершины
            }

    }

    // Возвращаем расстояния от начальной вершины до всех остальных
    return dist;
}

int main() {
    // Добавляем связи между спутниками
    adj["Azur"] = { "Intercosmos-Copernicus-500", "Explorer-1" };
    adj["Intercosmos-Copernicus-500"] = { "Azur", "Ariel 1" };
    adj["Explorer-1"] = { "Azur" };
    adj["Ariel 1"] = { "Intercosmos-Copernicus-500" };

    string start = "Azur"; // выбираем начальный спутник

    // Выполняем BFS от начального спутника
    unordered_map<string, int> dist = BFS(start);

    // Выводим кратчайшие расстояния от начального спутника до всех остальных
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
//// Создаем глобальную переменную для хранения связей между спутниками
//vector<vector<int>> adj(4);
//
//// Функция BFS для поиска кратчайшего пути от начального спутника до всех остальных
//vector<int> BFS(int start)
//{
//    queue<int> q; // очередь для хранения вершин графа
//    vector<int> dist(4, -1); // вектор для хранения расстояний от начальной вершины до всех остальных
//
//    // Инициализация начальной вершины
//    q.push(start);
//    dist[start] = 0;
//
//    // Основной цикл BFS
//    while (!q.empty())
//    {
//        int node = q.front(); // извлекаем вершину из очереди
//        q.pop();
//
//        // Перебираем все соседние вершины
//        for (int neighbour : adj[node])
//            // Если вершина еще не была посещена
//            if (dist[neighbour] == -1)
//            {
//                q.push(neighbour); // добавляем вершину в очередь
//                dist[neighbour] = dist[node] + 1; // обновляем расстояние до вершины
//            }
//
//    }
//
//    // Возвращаем расстояния от начальной вершины до всех остальных
//    return dist;
//}
//
//int main() {
//    // Добавляем связи между спутниками
//    adj[0] = { 1, 2 }; // Azur
//    adj[1] = { 0, 3 }; // Intercosmos-Copernicus-500
//    adj[2] = { 0 }; // Explorer-1
//    adj[3] = { 1 }; // Ariel 1
//
//    int start = 0; // выбираем начальный спутник (Azur)
//
//    // Выполняем BFS от начального спутника
//    vector<int> dist = BFS(start);
//
//    // Выводим кратчайшие расстояния от начального спутника до всех остальных
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
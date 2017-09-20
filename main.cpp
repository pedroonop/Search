#include <iostream>
#include "city.h"
#include "node.h"
#include "state.h"
#include "action.h"
#include <list>
#include <queue>
#include <set>

using namespace std;

void addEdge(list<pair<City, int> > graph[], City a, City b, int cost){
    graph[a].push_back(make_pair(b, cost));
    graph[b].push_back(make_pair(a, cost));
}

list<Action> largura(State begin, State end, list<pair<City, int> > graph[]){
    list<Action> solution;

    Node node;
    node.state = begin;
    node.cost = 0;
    node.father = nullptr;

    if (node.state == end)
        return solution;

    queue<Node> border;
    border.push(node);
    list<Node> explored;

    while (1){
        if (border.empty()){
            Action error;
            error.cost = -1;
            solution.push_back(error);
            return solution;
        }
        node = border.front();
        border.pop();
        explored.insert(explored.end(), node);
        for (list<pair<City, int> >::iterator it = graph[node.state.city].begin(); it != graph[node.state.city].end(); it++){
            Node son;
            son.state.city = it->first;
            son.cost = node.cost + it->second;
            son.father = &node;
            Action action;
            action.cost = it->second;
            action.from = node.state.city;
            action.to = son.state.city;
            son.action = action;
        }
    }

    return solution;
}

int main(){

    list<pair<City, int> > graph[20];

    addEdge(graph, Oradea, Zerind, 71);
    addEdge(graph, Arad, Zerind, 75);
    addEdge(graph, Arad, Sibiu, 140);
    addEdge(graph, Oradea, Sibiu, 151);
    addEdge(graph, Arad, Timisoara, 118);
    addEdge(graph, Timisoara, Lugoj, 111);
    addEdge(graph, Lugoj, Mehadia, 70);
    addEdge(graph, Mehadia, Drobeta, 75);
    addEdge(graph, Drobeta, Craiova, 120);
    addEdge(graph, Craiova, Pitesti, 138);
    addEdge(graph, Craiova, Rimnicu_Vilcea, 146);
    addEdge(graph, Pitesti, Rimnicu_Vilcea, 97);
    addEdge(graph, Rimnicu_Vilcea, Sibiu, 80);
    addEdge(graph, Sibiu, Fagaras, 99);
    addEdge(graph, Fagaras, Bucharest, 211);
    addEdge(graph, Bucharest, Pitesti, 101);
    addEdge(graph, Bucharest, Giurgiu, 90);
    addEdge(graph, Bucharest, Urziceni, 85);
    addEdge(graph, Hirsova, Urziceni, 98);
    addEdge(graph, Urziceni, Vaslui, 142);
    addEdge(graph, Vaslui, Iasi, 92);
    addEdge(graph, Iasi, Neamt, 87);
    addEdge(graph, Hirsova, Eforie, 86);


    return 0;
}


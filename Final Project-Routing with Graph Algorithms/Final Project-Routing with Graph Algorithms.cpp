// In The Name Of GOD
// Final Project-Routing with Graph Algorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <unordered_map>

#include <bits/stdc++.h>

#include "Headers/Edge.h"
#include "Headers/Reader.h"
#include "Headers/Point.h"
#include "Headers/Dijkstra.h"
#include "Headers/Analyser.h"
#include "Headers/Graph.h" 
#include "Headers/Query.h"
#include "Headers/Answer.h"
#include "Headers/Writer.h"

using namespace std;

int32_t main()
{
    Reader reader;
    reader.ReadMap();
    reader.ReadQueries();
    Graph graph = Graph(reader.points, reader.edgeIds);
    Analyser analyser = Analyser(graph, reader.queries);
    analyser.solve();
    Writer writer = Writer(analyser.analysedMap);
    writer.WriteAnswers();
    return false;
}

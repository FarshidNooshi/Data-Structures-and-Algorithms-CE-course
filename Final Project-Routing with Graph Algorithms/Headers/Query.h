#pragma once

class Query {
public:
    int src;
    int dst;
    int tme;

    Query(int tme, int src, int dst) {
        this->src = src;
        this->dst = dst;
        this->tme = tme;
    }
};
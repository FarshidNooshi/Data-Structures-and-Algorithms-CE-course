#pragma once

class Query {
public:
    int src;
    int dst;
    double tme;

    Query(double tme, int src, int dst) {
        this->src = src;
        this->dst = dst;
        this->tme = tme;
    }
};
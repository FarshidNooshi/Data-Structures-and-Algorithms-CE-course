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

    bool operator <(const Query& query) const {
        return this->tme < query.tme;
    }
};
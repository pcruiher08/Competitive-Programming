#include <iostream>
#include <vector>

class UnionFind {
public:
    UnionFind(int size) : parent(size), rank(size, 1) {
        for (int i = 0; i < size; ++i) {
            parent[i] = i; // Each element is initially its own root
        }
    }

    // Find the root of the set to which x belongs (with path compression)
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    // Union two sets (with union by rank)
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            // Union by rank: attach the smaller rank tree under the root of the larger rank tree
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

    // Check if elements x and y belong to the same set
    bool sameSet(int x, int y) {
        return find(x) == find(y);
    }

private:
    std::vector<int> parent;
    std::vector<int> rank;
};

int main() {
    int n = 5; // Number of elements

    UnionFind dsu(n);

    dsu.unite(0, 1);
    dsu.unite(2, 3);
    dsu.unite(0, 4);

    std::cout << "Are 1 and 4 in the same set? " << (dsu.sameSet(1, 4) ? "Yes" : "No") << std::endl;
    std::cout << "Are 2 and 4 in the same set? " << (dsu.sameSet(2, 4) ? "Yes" : "No") << std::endl;

    return 0;
}

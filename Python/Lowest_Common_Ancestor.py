######Binary lifting full
class RangeQuery:
    def __init__(self, data, func=min):
        self.func = func
        self._data = _data = [list(data)]
        i, n = 1, len(_data[0])
        while 2 * i <= n:
            prev = _data[-1]
            _data.append([func(prev[j], prev[j + i]) for j in range(n - 2 * i + 1)])
            i <<= 1

    def query(self, begin, end):
        depth = (end - begin).bit_length() - 1
        return self.func(self._data[depth][begin], self._data[depth][end - (1 << depth)])

#graph is an adjacency list
class LCA:
    def __init__(self, root, graph):
        self.time = [-1] * len(graph)
        self.path = [-1] * len(graph)
        self.distance = [0] * len(graph)
        P = [-1] * len(graph)
        t = -1
        dfs = [(root, 0)]
        while dfs:
            node, d = dfs.pop()
            self.distance[node] = d
            self.path[t] = P[node]
            self.time[node] = t = t + 1
            for nei in graph[node]:
                if self.time[nei] == -1:
                    P[nei] = node
                    dfs.append((nei, d + 1))
        self.rmq = RangeQuery(self.time[node] for node in self.path)

    def lca(self, a, b):
        if a == b:
            return a
        a = self.time[a]
        b = self.time[b]
        if a > b:
            a, b = b, a
        return self.path[self.rmq.query(a, b)]

    def dis(self, a, b):
        lc = self.lca(a, b)
        return self.distance[a] + self.distance[b] - 2 * self.distance[lc]


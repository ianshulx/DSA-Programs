import java.util.ArrayList;
import java.util.List;

class Graph {
    private int V;
    private List<Edge> edges;

    public Graph(int v) {
        V = v;
        edges = new ArrayList<Edge>();
    }

    public int getV() {
        return V;
    }

    public void setV(int v) {
        V = v;
    }

    public List<Edge> getEdges() {
        return edges;
    }

    public void setEdges(List<Edge> edges) {
        this.edges = edges;
    }

    public void addEdge(int u, int v, int w) {
        Edge e = new Edge(u, v, w);
        edges.add(e);
    }
}

class Edge {
    private int u;
    private int v;
    private int w;

    public int getU() {
        return u;
    }

    public void setU(int u) {
        this.u = u;
    }

    public int getV() {
        return v;
    }

    public void setV(int v) {
        this.v = v;
    }

    public int getW() {
        return w;
    }

    public void setW(int w) {
        this.w = w;
    }

    public Edge(int u, int v, int w) {
        this.u = u;
        this.v = v;
        this.w = w;
    }
}

public class BelmannFord {
    public static void main(String args[]) {
        Graph g = createGraph();
        int distance[] = new int[g.getV()];
        boolean hasNegativeCycle = getShortestPaths(g, 1, distance);
        if (!hasNegativeCycle) {
            System.out.println("Vertex \t: Distance");
            for (int i = 1; i < distance.length; i++)
                System.out.println("\t" + i + " " + "\t\t" + (distance[i] == Integer.MAX_VALUE ? "-" : distance[i]));
        } else {
            System.out.println("Negative cycle exists in the graph, no solution found!!!");
        }
    }

    private static Graph createGraph() {
        int v = 7;
        Graph g = new Graph(v);
        g.addEdge(1, 2, 4);
        g.addEdge(1, 4, 9);
        g.addEdge(2, 3, -1);
        g.addEdge(3, 6, 3);
        g.addEdge(4, 3, 2);
        g.addEdge(4, 5, -5);
        g.addEdge(5, 6, 0);
        return g;
    }

    public static boolean getShortestPaths(Graph g, int source, int[] distance) {
        int V = g.getV();
        for (int i = 1; i < V; i++) {
            distance[i] = Integer.MAX_VALUE;
        }
        distance[source] = 0;
        for (int i = 1; i < V; i++) {
            for (Edge e : g.getEdges()) {
                int u = e.getU(), v = e.getV(), w = e.getW();
                if (distance[u] != Integer.MAX_VALUE && distance[v] > distance[u] + w) {
                    distance[v] = distance[u] + w;
                }
            }
        }
        for (Edge e : g.getEdges()) {
            int u = e.getU(), v = e.getV(), w = e.getW();
            if (distance[u] != Integer.MAX_VALUE && distance[v] > distance[u] + w) {
                return true;
            }
        }
        return false;
    }
}
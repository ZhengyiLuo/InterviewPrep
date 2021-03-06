import java.util.Collection;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;

/**
 * @Time: Nov 5, 2016
 * @Author: zen
 */

public class LeetcodeSolu8 {

    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        if (n == 1) {
            List<Integer> result = new LinkedList<>();
            result.add(0);
            return result;

        }
        if (n == 2) {
            List<Integer> result = new LinkedList<>();
            result.add(edges[0][0]);
            result.add(edges[0][1]);
            return result;

        }
        HashMap<Integer, GraphNode> graph = new HashMap<>();
        GraphNode node1;
        GraphNode node2;
        int n1;
        int n2;

        for (int i = 0; i < edges.length; i++) {
            n1 = edges[i][0];
            n2 = edges[i][1];
            if (graph.containsKey(n1)) {
                node1 = graph.get(n1);
            } else {
                node1 = new GraphNode(n1);
                graph.put(n1, node1);
            }

            if (graph.containsKey(n2)) {
                node2 = graph.get(n2);
            } else {
                node2 = new GraphNode(n2);
                graph.put(n2, node2);
            }

            node1.addNode(node2);
            node2.addNode(node1);
        }

        while (true) {
            Collection<GraphNode> nodesSet = graph.values();
            HashSet<Integer> removes = new HashSet<>();
            for (Iterator iterator = nodesSet.iterator(); iterator.hasNext();) {
                GraphNode graphNode = (GraphNode) iterator.next();
                if (graphNode.getDegree() == 1) {
                    removes.add(graphNode.id);
                }
            }
            for (Iterator iterator2 = removes.iterator(); iterator2.hasNext();) {
                Integer integer = (Integer) iterator2.next();
                GraphNode graphNode = graph.get(integer);
                graphNode.getSingle().removeNode(graphNode);
                graph.remove(integer);
            }

            if (graph.size() == 1 || graph.size() == 2) {
                break;
            }

        }
        List<Integer> result = new LinkedList<>();

        for (Iterator iterator = graph.values().iterator(); iterator.hasNext();) {
            GraphNode node = (GraphNode) iterator.next();
            result.add(node.id);
        }

        return result;
    }

    public class GraphNode {
        HashSet<GraphNode> outlinks;
        int id;
        int degree;

        public GraphNode(int id) {
            this.outlinks = new HashSet<>();
            this.id = id;
            this.degree = 0;
        }

        public void removeNode(GraphNode n) {
            outlinks.remove(n);
            --degree;
        }

        void addNode(GraphNode node) {
            outlinks.add(node);
            degree++;
        }

        GraphNode getSingle() {
            return outlinks.iterator().next();

        }

        public int getDegree() {
            return degree;
        }

    }

}

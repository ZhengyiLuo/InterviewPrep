//#include<iostream>
//using namespace std;
//
//#define INFINITY 9999
//#define MAX_VERTEX_NUM 20
//
//typedef int weight;
//typedef int InfoType;
//typedef int VertexType;
//
//
//typedef struct ArcCell{
//	weight adj;
//	InfoType *info;
//}ArcCell, AdjMatrx[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
//
//typedef struct MGraph{
//	VertexType vex[MAX_VERTEX_NUM];
//	AdjMatrx arcs;
//	int vexnum, arcnum;
//
//};
//
//typedef struct ArcNode{
//	int adjvex;
//	struct ArcNode * nextarc;
//};
//
//typedef struct VNode{
//	VertexType data;
//	ArcNode * firstarc;
//} AdjList[MAX_VERTEX_NUM];
//
//typedef struct ALGraph{
//	AdjList vertices;
//	int vexnum, arcnum;
//};
//
//typedef struct edges{
//	VertexType adjvex;
//	int lowcost;
//}closedge[MAX_VERTEX_NUM];
//
//
//int CreatUND(MGraph &G);
//int CreatlinkedGraph(ALGraph &P, MGraph G);
//int LocateVex(MGraph G, int v);
//int NextAdjVex(ALGraph G, int v, int w);
//int FirstAdjVex(ALGraph G, int v);
//int VisitFunc(ALGraph G, int v);
//void DFSTraverse(ALGraph G);
//void DFS(ALGraph G, int v);
//void MiniSpanTree_Prim(MGraph G, VertexType u);
//int minimu(closedge closedge, int length);
//bool visited[MAX_VERTEX_NUM];
//
//int main(){
//
//	MGraph G;
//	ALGraph P;
//	ArcNode *p;
//	int i, j, k, v, w;
//	
//	CreatUND(G);
//	for (i = 0; i < G.vexnum; i++)
//	{
//		for (j = 0; j < G.vexnum; j++)
//		{
//			cout << G.arcs[i][j].adj<<"\t";
//		}
//		cout << endl;
//	}
//
//	//CreatlinkedGraph(P, G);
//	
//	cout << endl;
//	cout << endl;
//	MiniSpanTree_Prim(G, 1);
//
//	//DFSTraverse(P);
//
//	//for ( i = 0; i < P.vexnum; i++)
//	//{
//	//	v = i;
//	//	for (w = FirstAdjVex(P, v); w != -1; w = NextAdjVex(P, v, w)){
//	//		cout << P.vertices[w].data << "  ";
//
//	//	}
//	//	cout << endl;
//	//}
//	/*cout << endl;
//	cout << endl;
//	cout << endl;
//	for (i = 0; i < P.vexnum; i++)
//	{
//		if (P.vertices[i].firstarc != NULL){
//			p = P.vertices[i].firstarc;
//			cout << P.vertices[i].data<<"  the link is:";
//			while (p != NULL)
//			{
//				cout << p->adjvex+1 << "    ";
//				p = p->nextarc;
//			}
//
//
//		}
//		cout << endl;
//	}*/
//
//	system("pause");
//
//}
//
//int CreatlinkedGraph(ALGraph &P, MGraph G){
//	int i, j, k, w;
//	int v1, v2;
//	ArcNode *arc, *store = NULL;
//	P.vexnum = G.vexnum;
//	P.arcnum = G.arcnum;
//
//	
//	for (i = 0; i < G.vexnum; i++){
//		P.vertices[i].data = G.vex[i];
//	}
//	for (i = 0; i < G.vexnum; i++)
//	{
//		arc = new ArcNode;
//		P.vertices[i].firstarc = arc;
//		for (j = 0; j < G.vexnum; j++)
//		{   
//			if (G.arcs[i][j].adj != INFINITY){
//				arc->nextarc = new ArcNode;
//				arc->adjvex = j;
//				store = arc;
//				arc = arc->nextarc;
//			}
//
//		}
//		store->nextarc = NULL;
//	}
//
//
//	return 0;
//}
//
//int CreatUND(MGraph &G){
//	int i, j, k, w;
//	int v1, v2;
//	
//	cout << "Please enter the nuber of vexes" << endl;
//	cin >> G.vexnum;
//	cout << "please enter the number of arcnums" << endl;
//	cin >> G.arcnum;
//	for (i = 0; i < G.vexnum; i++){
//		cout << "Please enter the vexes" << endl;
//		cin >> G.vex[i];
//	}
//	for (i = 0; i < G.vexnum; i++)
//	{
//		for ( j = 0; j < G.vexnum; j++)
//		{
//			G.arcs[i][j] = { INFINITY, NULL };
//		}
//	}
//	for ( k = 0; k < G.arcnum; k++)
//	{
//		cout << "Please enter v1" << endl;
//		cin >> v1;
//		cout << "please enter v2" << endl;
//		cin >> v2;
//		cout << "please enter weight" << endl;
//		cin >> w;
//
//		i = LocateVex(G, v1);
//		j = LocateVex(G, v2);
//		G.arcs[i][j].adj = w;
//		G.arcs[j][i].adj = w;
//	}
//
//	return 0;
//}
//
//int LocateVex(MGraph G, int v){
//	int i;
//	for (i = 0; i < G.vexnum; i++)
//		if (G.vex[i] == v)
//			return i;
//	return 0;
//}
//
//int NextAdjVex(ALGraph G, int v, int w){
//	ArcNode *p = NULL;
//	p = G.vertices[v].firstarc;
//	while (p->nextarc){
//		if (p->adjvex == w)
//		{
//			return p->nextarc->adjvex;
//		}
//		p = p->nextarc;
//	}
//	return -1;
//
//}
//
//int FirstAdjVex(ALGraph G, int v){
//	if (G.vertices[v].firstarc)
//	return G.vertices[v].firstarc->adjvex;
//	else return -1;
//}
//
//int VisitFunc(ALGraph G, int v){
//	cout << G.vertices[v].data << endl;
//	return 0;
//}
//
//void DFSTraverse(ALGraph G){
//	int i;
//	for ( i = 0; i < G.vexnum; i++)
//	{
//		visited[i] = false;
//	}
//	DFS(G, 3);
//}
//
//void DFS(ALGraph G, int v){
//	int w;
//	visited[v] = true;
//	VisitFunc(G, v);
//	for (w = FirstAdjVex(G, v); w != -1; w = NextAdjVex(G, v, w)){
//		if (!visited[w]) DFS(G, w);
//	}
//
//
//}
//
//void MiniSpanTree_Prim(MGraph G, VertexType u){
//	int k, j, i;
//	closedge closedge;
//	k = LocateVex(G, u);
//	for (j = 0; j < G.vexnum; j++){
//		if (j != k)
//			closedge[j] = { u, G.arcs[k][j].adj };
//		else closedge[j].lowcost = 0;
//	}
//		closedge[k].lowcost = 0;
//	for ( i = 0; i < G.vexnum; i++)
//	{
//		k = minimu(closedge, G.vexnum);
//		if (k == -1) break;
//		cout << closedge[k].adjvex << " -> " << G.vex[k] << endl;
//		closedge[k].lowcost = 0;
//		for (j = 0; j < G.vexnum; j++)
//		{
//			if (G.arcs[k][j].adj<closedge[j].lowcost)
//			{
//				closedge[j] = { G.vex[k], G.arcs[k][j].adj };
//			}
//		}
//	}
//
//
//}
//
//int minimu(closedge closedge, int length){
//	int i ,j, min, store = -1;
//	min = INFINITY;
//	for (i = 0; i < length; i++)
//	{
//		if (closedge[i].lowcost != 0 && min > closedge[i].lowcost){
//			min = closedge[i].lowcost;
//			store = i;
//		}
//	}
//	 return store;
//}
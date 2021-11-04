////
//// Created by Jason on 2021/7/9.
////
//#include <cstdio>
//
///**
// * 邻接矩阵法
// */
//#define MaxVertexNum 100    //顶点数目的最大值
//typedef char VertexType;    //顶点的数据类型
//typedef int EdgeType;       //带权图中边上权值的数据类型
//typedef struct {
//    VertexType Vex[MaxVertexNum];               //顶点表
//    EdgeType Edge[MaxVertexNum][MaxVertexNum];  //邻接矩阵，边表
//    int vexNum, arcNum;                         //图的当前顶点数和弧数
//}MGraph;
//
//typedef MGraph Graph;
//
///**
//* 邻接表法
//*/
//#define MaxVertexNum 100    //图中顶点数目的最大值
//typedef struct ArcNode {    //边表节点
//    int adjVex;             //该弧所指向的顶点的位置
//    struct ArcNode *next;   //指向下一条弧的指针
//    //InfoType info;        //网的边权值
//}ArcNode;
//typedef struct VNode {      //顶点表结点
//    VertexType data;        //顶点信息
//    ArcNode *first;         //指向第一条依附该顶点的弧的指针
//}VNode, AdjList[MaxVertexNum];                          //test
//typedef struct {
//    AdjList vertices;       //邻接表
//    int vexNum, arcNum;     //图的顶点数和弧数
//}ALGraph;                   //ALGraph是以邻接表存储的图类型
//
////typedef ALGraph Graph;
//
///**
//* 图的基本操作
// * Adjacent(G,x,y):判断图G是否存在边<x,y>或(x,y)。
// * Neighbors(G,x):列出图G中与结点x邻接的边。
// * InsertVertex(G,x):从图G中插入顶点x。
// * DeleteVertex(G,x):从图G中删除顶点x。
// * AddEdge(G,x,y):若无向边(x,y)或有向边<x,y>不存在，则向图G中添加该边。
// * RemoveEdge(G,x,y):若无向边(x,y)或有向边<x,y>存在，则从图G中删除该边。
// * FirstNeighbor(G,x):求图G中顶点x的第一个邻接点，若有则返回顶点号。若x没有邻接点或图中不存在x，则返回-1。
// * NextNeighbor(G,x,y):假设图G中顶点y是顶点x的一个邻接点，返回除y外顶点x的下一个邻接点的顶点号，若y是x的最后一个邻接点，则返回-1。
// * Get_edge_value(G,x,y):获取图G中边(x,y)或<x,y>对应的权值。
// * Set_edge_value(G,x,y,v):设置图G中边(x,y)或<x,y>对应的权值为v。
//*/
//
///**
//* 广度优先搜索
//*/
//#define MAX_VERTEX_NUM 10
//bool visited[MAX_VERTEX_NUM];           //访问标记数组
//void BFS(Graph G, int v);
//
//void BFSTraverse(Graph G) {             //对图G进行广度优先遍历
//    for (int i = 0; i < G.vexNum; ++i)
//        visited[i] = false;             //访问标记数组初始化
////    InitQueue(Q);                     //初始化辅助队列Q
//    for (int i = 0; i < G.vexNum; ++i)  //从0号顶点开始遍历
//        if (!visited[i])                //对每个连通分量调用一次BFS
//            BFS(G, i);                  //v_i未访问过，从v_i开始BFS
//}
//
//void BFS(Graph G, int v) {              //从顶点v出发，广度优先遍历图G
//    visit(v);                           //访问初始顶点v
//    visited[v] = true;                  //对v做已访问标记
//    EnQueue(Q, v);                      //顶点v入队列Q
//    while (!isEmpty(Q)) {
//        DeQueue(Q, v);                  //顶点v出队列
//        for (w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w))
//                                        //检测v所有邻接点
//            if (!visited[w]) {          //w为v的尚未访问的邻接顶点
//                visit(w);               //访问顶点w
//                visited[w] = true;      //对w做已访问标记
//                EnQueue(Q, w);          //顶点w入队列
//            }
//    }
//}
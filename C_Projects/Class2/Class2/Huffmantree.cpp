//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#define  MAX_NODE  200     //   Max_Node>2n-1  
//typedef struct
//{   
//	unsigned int Weight;   // Ȩֵ��  
//	unsigned int Parent , Lchild , Rchild ;
//}HTNode;
//HTNode HT[MAX_NODE];
//char *HC[MAX_NODE];
//
//void Create_Huffman(unsigned n, HTNode HT[], unsigned m) 
////  ����һ��Ҷ�ӽ����Ϊn��Huffman�� 
//{  
//	unsigned int w;
//	unsigned int k,j;
//	printf("\n Please input the normalised weights of %d characters:\n",n);
//	for(k=1; k<=m; k++)
//	{  
//		if(k<=n)
//		{  
//			printf("\n Please input weight: w[%d]=?   ",k);
//			scanf("%d", &w); 
//			HT[k].Weight=w;  
//		}               //  ����Ȩֵ  
//		else  
//			HT[k].Weight=0;  	
//		HT[k].Parent=HT[k].Lchild=HT[k].Rchild=0;
//	}                                                  // ��ʼ������HT 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////
//	for(k=1; k<=m; k++)
//	{   
//		printf("\n%8d%8d%8d%8d", HT[k].Weight,HT[k].Parent,HT[k].Lchild,HT[k].Rchild);
//               
//	}
//    printf("\n-----------being initialized successfully!----------  \n \n \n \n ");
///////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//	for(k=n+1; k<=m; k++)
//	{
//		unsigned w1=101, w2=w1;      //w1 , w2�ֱ𱣴�Ȩֵ��С������Ȩֵw1<=w2
//		int  p1=0, p2=0;             // p1 , p2����������СȨֵ���±�  
//		for(j=1;j<=k-1;j++)
//		{
//			if(HT[j].Parent==0)    // ��δ�ϲ� 
//			{   
//				if (HT[j].Weight<w1)
//					{
//						w2=w1; 
//						p2=p1;
//						w1=HT[j].Weight;
//						p1=j;  
//					}
//					else if (HT[j].Weight<w2)
//					{  
//						w2=HT[j].Weight;
//						p2=j;
//					}
//			}    //  �ҵ�Ȩֵ��С������ֵ�����±�  
//		}
//     HT[k].Lchild=p1; 
//	 HT[k].Rchild=p2;
//     HT[k].Weight=w1+w2;
//     HT[p1].Parent=k; 
//	 HT[p2].Parent=k; 
//	}
//}
//
//void Huff_coding(unsigned n, HTNode HT[])  
//{   
//	unsigned int  k, sp, p, fp;
//	char *cd;
//    cd=(char*)malloc((n+1)*sizeof(char)); //  ��̬���������Ĺ����ռ�
//	cd[n]='\0';    //  ����Ľ�����־ 
//	for (k=1; k<=n; k++)       //������ַ��ı���    
//	{  
//		sp=n; 
//		p=k; 
//		fp=HT[k].Parent; 
//		for(  ; fp!=0; p=fp, fp=HT[p].Parent)  //   ��Ҷ�ӽ�㵽�����������   
//		if(HT[fp].Lchild==p)  
//			cd[--sp]='0';
//		else  cd[--sp]='1';
//		HC[k]=(char*)malloc((n-sp)*sizeof(char));  //  Ϊ��k���ַ����䱣�����Ŀռ� 
//		strcpy(HC[k], &cd[sp]);
//	}
//	free(cd);
//}
//
//void main()
//{
//	int k,m;
//	int n=8; 
//	m=2*n-1;	
//	Create_Huffman(n, HT, m);
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	for(k=1; k<=m; k++)
//	{   
//				printf("\n%8d%8d%8d%8d", HT[k].Weight,HT[k].Parent,HT[k].Lchild,HT[k].Rchild);
//               
//	}
//	printf("\n ----------being optimized successfully!--------\n");
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Huff_coding(n,HT); 
//    
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	for(k=1; k<=n; k++)
//	{   
//				printf("\n%d-->%s", k,HC[k]);
//               
//	}
//	printf("\n ----------being coded successfully!--------\n\n\n");
//	////////////////////////////////////////////////////////////////////////////////////////////////////////
//}
//

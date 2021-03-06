//Program: To findout connected components in graph

#include<iostream>
#define max_vertices 1000
int dfs(int);
int display();
int scan_tree(int);
int display_cong();

 int ud[max_vertices];
 int uf[max_vertices];
 int up[max_vertices];
 int color[max_vertices]; // 1=white,2=gray,3=black
 int time1;
 int j=0;
 int k=0;
 int graph[max_vertices][max_vertices];
 //int graph[6][6]={{0,1,0,1,0,0},{0,0,0,0,1,0},{0,0,0,0,1,1},{0,1,0,0,0,0},{0,0,0,1,0,0},{0,0,0,0,0,1}};
 int cong[max_vertices];
 int p=max_vertices+1;
 int n;
 
int main()
{
    printf("Enter number of vertices\n");
    scanf("%d",&n);
    scan_tree(n);
     for(int i=0;i<n;i++)
     {
           color[i]=1;
           up[i]=0;
     }
 
     int time1=0;
     for(int j=0;j<n;j++)
     {
         if(color[j]==1)
         {
                        dfs(j);
                        //printf("k in main=%d\n",k);
                        cong[k++]=j;
                        cong[k++]=99;
                        cong[k]=p;                 
         }
     }
     display();
     display_cong();
     system("pause");     
}


int dfs(int i)
{
    //printf("value of node when dfs called=%d\n",i);
 time1+=1;
 ud[i]=time1;
 color[i]=2;
 j=0;
 
 for(int j=0;j<n;j++)
 {
         if(graph[i][j]==1 && color[j]==1)
         {
                up[j]=i;               
                dfs(j);
                time1+=1;
                uf[j]=time1;
                color[j]=3;
                //printf("node pop=%d\n",j);
               //printf("k=%d\n",k);
                cong[k++]=j;
                
                dfs(up[j]);
              
         } 
         
  } // end of while     
}



int display()
{
    for(int i=0;i<n;i++)
    {
            //printf("color of node= %d is %d   %d   %d\n",i,color[i],ud[i],uf[i]);
      //      cout<<"color of node="<<i<<"is "<<color[i]<<endl;    
    }
}

int scan_tree(int n)
{
      printf("Enter tree elements..\n");
    for(int i=0;i<n;i++)
    {
         for(int j=0;j<n;j++)
         {
                 scanf("%d",&graph[i][j]);
            //printf("%d  ",graph[i][j]);
          //      cout<<"color of node="<<i<<"is "<<color[i]<<"  ud="<<endl;    
         }printf("\n");            
    } printf("\n\n");             
}

int display_cong()
{
    printf("Connected graph are..\n\n"); 
    for(int i=0;i<100;i++)
    {
            if(cong[i]==p)
                           break;  
            if(cong[i]==99) 
                  printf("\n\n"); 
             else  
                   printf("%d ",cong[i]);
                   
        
    }            
}

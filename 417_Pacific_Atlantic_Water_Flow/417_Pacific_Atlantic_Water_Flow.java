class Node{
  int x;
  int y;
  public Node(int x,int y){
    this.x=x;
    this.y=y;
  }
}
public class Solution {
    int n;
    int m;
    public List<int[]> pacificAtlantic(int[][] matrix) {
        List<int[]> result=new ArrayList<>();
        if(matrix==null || matrix.length==0 ||matrix[0].length==0){
          return  result;
        }
        n=matrix.length;
        m=matrix[0].length;
        boolean[][] pacific=new boolean[n][m];
        boolean[][] atlantic=new boolean[n][m];
        for(int i=0;i<n;i++){
          if(!pacific[i][0]){
            bfs(matrix,i,0,pacific);
          }
        }
        for(int j=0;j<m;j++){
          if(!pacific[0][j]){
            bfs(matrix,0,j,pacific);
          }
        }
        for(int i=0;i<n;i++){
          if(!atlantic[i][m-1]){
            bfs(matrix,i,m-1,atlantic);
          }
        }
        for(int j=0;j<m;j++){
          if(!atlantic[n-1][j]){
            bfs(matrix,n-1,j,atlantic);
          }
        }
        for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
            if(pacific[i][j] && atlantic[i][j]){
              result.add(new int[]{i,j});
            }
          }
        }
        return result;
    }
    public void bfs(int[][] matrix,int x,int y,boolean[][] visited){
      int[] dx={1,0,-1,0};
      int[] dy={0,1,0,-1};
      Node node=new Node(x,y);
      Queue<Node> queue=new LinkedList<>();
      queue.offer(node);
      visited[node.x][node.y]=true;
      while (!queue.isEmpty()) {
        Node cur=queue.poll();
        for(int j=0;j<4;j++){
          int nextX=cur.x+dx[j];
          int nextY=cur.y+dy[j];
          if(nextX>=0 && nextX<n && nextY>=0 && nextY<m
          && !visited[nextX][nextY] && matrix[nextX][nextY]>=matrix[cur.x][cur.y] ){
            Node next=new Node(nextX,nextY);
            queue.offer(next);
            visited[next.x][next.y]=true;
          }
        }
      }
    }
}

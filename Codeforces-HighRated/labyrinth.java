// https://codeforces.com/contest/1666/problem/L

 import java.util.ArrayList;
import java.util.Scanner;
 
public class Labyrinth {
 
	static Scanner sc;
	static Room rooms[];
	static boolean isVisited[]; 
	static int start;
	static int end;
	static int p1[], p2[];
	static int p1c, p2c;
	static int bCount;
	public static void main(String args[]){  	  
		  sc = new Scanner(System.in);
		  int N = sc.nextInt();
		  int M = sc.nextInt();
		  start = sc.nextInt();
		  end = 0;
		 isVisited = new boolean[N+1];
		  p1 = new int[N];
		  p2 = new int[N];		 
		  rooms = new Room[N+1];
		  for(int i = 0; i <= N; i++) {
			  rooms[i] = new Room();
		  }
		  for(int i = 0; i < M; i++) {
			  int a = sc.nextInt();
			  int b = sc.nextInt();
			  rooms[a].connected.add(b);
			  rooms[b].cons++;
		  }
		  bCount = N + 1;
		  if(rooms[start].connected.size() < 2)
			  System.out.println("Impossible");
		  else {
			  boolean found = false;
			  for(int x = 1; x <= N && !found; x++) {
				  if( x == start || rooms[x].cons < 2)
					  continue;
				  end = x;
				  isVisited = new boolean[N+1];
				  player1(0, start, 0);
				  bCount = 0;
				  isVisited[start] = false;
				  if(player2(0, start, 0)) {
					  System.out.println("Possible");
					  System.out.println(p1c + 1);
					  for(int r = 0; r <= p1c; r++) 
						  System.out.print(p1[r] + " ");
					  System.out.println();
					  System.out.println(p2c + 1);
					  for(int r = 0; r <= p2c; r++) 
						  System.out.print(p2[r] + " ");
					  found = true;
				  }
			  }
			  if(!found)			
				  System.out.println("Impossible");
		  }
		  sc.close();
	}
	
	private static boolean player2(int pre, int go, int count) {
		if(isVisited[go])
			return false;
		
		if(go == end) {
			for(int i : rooms[pre].visited)
				if(i == go)
					return false;
			p2[count] = go;
			p2c = count;
			return true;
		}
		p2[count] = go;
		isVisited[go] = true;
		for(int i : rooms[go].connected)
			if(player2(go, i, count + 1)) 
				return true;
			
		return false;
	}
	
	static boolean player1(int pre, int go, int count) {
		if(isVisited[go])
			return false;
		p1[count] = go;
		rooms[pre].visited.add(go);
		if(go == end) {
			p1c = count;
			return true;
		}
		isVisited[go] = true;
		for(int i :rooms[go].connected) {
			if(player1(go, i, count + 1))
				return true;
		}	
		return false;
	}
	static class Room{
		int mId;
		ArrayList<Integer> connected = new ArrayList<>();
		ArrayList<Integer> visited = new ArrayList<>();
		int cons;
	}
 
}
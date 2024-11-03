// https://codeforces.com/contest/1702/problem/E


import java.util.*;
import java.io.*;
import java.lang.*;
public class Main {
	public static boolean rec(List<Integer> edges[],boolean vis[],int i,boolean cnt){
		// System.out.println(i+" "+cnt);
		for(int x:edges[i]){
			if(!vis[x]){
				vis[x] = true;
				return rec(edges,vis,x,!cnt);
			}
		}
		return !cnt;
	}
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-->0){
			int n = sc.nextInt();
			List<Integer> edges[] = new ArrayList[n];
			for(int i=0;i<n;i++){
				edges[i] = new ArrayList<>();
			}
			for(int i=0;i<n;i++){
				int x = sc.nextInt();
				int y = sc.nextInt();
				edges[x-1].add(y-1);
				edges[y-1].add(x-1);
			}
			boolean vis[] = new boolean[n];
			boolean ans = true;
			for(int i=0;i<n && ans;i++){
				if(edges[i].size()!=2){
					ans = false;
				}
			}
			for(int i=0;i<n && ans;i++){
				if(!vis[i]){
					vis[i] = true;
					if(!rec(edges,vis,i,true)){
						// System.out.println(i);
						ans = false;
					}
				}
			}
			if(ans){
				System.out.println("YES");
			}
			else{
				System.out.println("NO");
			}
		}
	}
}
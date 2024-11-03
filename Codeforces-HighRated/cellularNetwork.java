// https://codeforces.com/contest/702/problem/C
import java.io.*;
import java.util.*;
public class CellularNetwork {
  static class InputReader {
    BufferedReader reader;
    StringTokenizer tokenizer;
    public InputReader(InputStream stream) {
      reader = new BufferedReader(new InputStreamReader(stream), 32768);
      tokenizer = null;
    }
    String next() { // reads in the next string
    while (tokenizer == null || !tokenizer.hasMoreTokens()) {
      try {
        tokenizer = new StringTokenizer(reader.readLine());
      } catch (IOException e) {
        throw new RuntimeException(e);
      }
    }
    return tokenizer.nextToken();
    }
    String nextLine(){
      String line = null;
      try {
        line = reader.readLine();
      } catch (IOException e) {
        throw new RuntimeException(e);
      }
      return line;
    }
    public int nextInt() { // reads in the next int
    return Integer.parseInt(next());
    }
    public long nextLong() { // reads in the next long
      return Long.parseLong(next());
    }
    public double nextDouble() { // reads in the next double
      return Double.parseDouble(next());
    }
  }
  
  static InputReader r = new InputReader(System.in);
  static PrintWriter pw = new PrintWriter(System.out);

  public static void main(String[] args) {
    int n = r.nextInt();
    int m = r.nextInt();
    String[] stTemp1 = r.nextLine().split(" ");
    String[] stTemp2 = r.nextLine().split(" ");
    Integer[] cities = new Integer[n];
    Integer[] towers = new Integer[m];
    int temp = Math.max(n, m);
    for(int i = 0; i < temp; i++){
      if(i < n){
        cities[i] = Integer.parseInt(stTemp1[i]);
      }
      if(i < m){
        towers[i] = Integer.parseInt(stTemp2[i]);
      }
    }
    long low = 0;
    long high = (long) Integer.MAX_VALUE;
    while(low < high){
      long mid = low + (high - low)/2;
      boolean check = true;
      //Function Condition
      int i =0;
      int j = 0;
      while(i < n && j < m){
        int dist = Math.abs(cities[i] - towers[j]);
        if(dist > mid){
          if(j+1 < m){
            j++;
          }else{
            check = false;
            break;
          }
        }else{
          i++;
        }
      }
      //End
      if(check){
        high = mid;
      }else{
        low = mid + 1;
      }
    }
    pw.println(low);
    pw.close();
  }
}
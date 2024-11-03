// https://codeforces.com/contest/1201/problem/C

import java.io.*;
import java.util.*;
public class MaximumMedian{
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
    int k = r.nextInt();
    String[] arr = r.nextLine().split(" ");
    Integer[] a = new Integer[n];
    for(int i = 0; i < n; i++){
      a[i] = Integer.parseInt(arr[i]);
    }
    Arrays.sort(a);
    // for(int i = 0; i < n; i++){
    //   pw.print(a[i] + " ");
      
    // }
    // pw.println();
    int low = 0;
    int high = (int) 2e9;
    while(low < high){
      int mid = low + (high-low+1)/2;
      // pw.println(mid);
      long opsNeeded = 0;
      for(int i = (n-1)/2; i < n; i++){
        opsNeeded += Math.max(0, (mid-a[i]));
      }
      
      if(opsNeeded <= k){
        low = mid;
      }else{
        high = mid -1;
      }
      
    }
    pw.println(low);
    pw.close();
  }
}
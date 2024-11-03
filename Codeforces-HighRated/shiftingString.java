// https://codeforces.com/contest/1690/problem/F


// import java.io.*;
// import java.util.*;
// public class Main {
//   static class InputReader {
//     BufferedReader reader;
//     StringTokenizer tokenizer;
//     public InputReader(InputStream stream) {
//       reader = new BufferedReader(new InputStreamReader(stream), 32768);
//       tokenizer = null;
//     }
//     String next() { // reads in the next string
//     while (tokenizer == null || !tokenizer.hasMoreTokens()) {
//       try {
//         tokenizer = new StringTokenizer(reader.readLine());
//       } catch (IOException e) {
//         throw new RuntimeException(e);
//       }
//     }
//     return tokenizer.nextToken();
//     }
//     String nextLine(){
//       String line = null;
//       try {
//         line = reader.readLine();
//       } catch (IOException e) {
//         throw new RuntimeException(e);
//       }
//       return line;
//     }
//     public int nextInt() { // reads in the next int
//     return Integer.parseInt(next());
//     }
//     public long nextLong() { // reads in the next long
//       return Long.parseLong(next());
//     }
//     public double nextDouble() { // reads in the next double
//       return Double.parseDouble(next());
//     }
//   }
  
//   public static int letterRepetition(String t){
//     int length = t.length();
//     int[] patterns = new int[length];
//     int i = 1;
//     int l = 0;
//     while (i < length) {
//         if (t.charAt(i) == t.charAt(l)) {
//             ++l;
//             patterns[i] = l;
//             ++i;
//         } else if (l > 0) {
//             l = patterns[l - 1];
//         } else {
//             ++i;
//         }
//     }
//     if (length % (length - patterns[length]) == 0) return length - patterns[length];
//     return length;
// }
//   private static long gcd(int a, int b){
//     while (b > 0){
//         int temp = b;
//         b = a % b;
//         a = temp;
//     }
//     return a;
// }
//   private static long lcm(int a, int b){
//     return a * (b / gcd(a, b));
// }
//   static InputReader r = new InputReader(System.in);
//   static PrintWriter pw = new PrintWriter(System.out);

//   public static void main(String[] args) {
//     int t = r.nextInt();
//     for(int i = 0; i < t; i++){
      
//       int n = r.nextInt();
//       int[] adj;
//       boolean[] visited;
//       char s[];
//       adj = new int[n+1];
//       visited = new boolean[n+1];
//       s = r.nextLine().toCharArray();
//       String[] temp = r.nextLine().split(" ");
//       for(int j = 1; j < n+1; j++){
//         adj[j]=Integer.parseInt(temp[j-1]);
//       }
//       long ans = 1;
//       for(int j = 1; j < n+1; j++){
//         if(visited[j]) continue;
//         StringBuilder str = new StringBuilder();
//         int idx = i;
//         while(!visited[idx]){
//           str.append(s[idx]);
//           visited[idx] = true;
//           idx = adj[idx];
//         }
//         ans = lcm((int)ans, letterRepetition(str.toString()));
//       }
//       pw.println(ans);
//     }
//     pw.close();
//   }
// }
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;
 
 
public class ShiftingString {
    static int KMP(String t) {
        int m = t.length();
        int lps[] = new int[m];
        int i = 1;
        int l = 0;
        while (i < m) {
            if (t.charAt(i) == t.charAt(l)) {
                ++l;
                lps[i] = l;
                ++i;
            } else if (l > 0) {
                l = lps[l - 1];
            } else {
                ++i;
            }
        }
        if (m % (m - lps[m - 1]) == 0) return m - lps[m - 1];
        return m;
    }
 
    public static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }
 
    public static long lcm(long a, long b) {
        if (a == 0) return b;
        if (b == 0) return a;
        return a / gcd(a, b) * b;
    }
 
    public static void main(String[] args) throws IOException {
        fs = new FastReader();
        out = new PrintWriter(System.out);
        int t = fs.nextInt();
        while (t-- > 0) {
            int n = fs.nextInt();
            char s[] = fs.next().toCharArray();
            int p[] = new int[n];
            for (int i = 0; i < n; ++i) {
                p[i] = fs.nextInt() - 1;
            }
            long ans = 0;
            boolean[] vis = new boolean[n];
            for (int i = 0; i < n; ++i) {
                if (vis[i]) continue;
                StringBuilder res = new StringBuilder();
                int j = i;
                while (!vis[j]) {
                    res.append(s[j]);
                    vis[j] = true;
                    j = p[j];
                }
                ans = lcm(ans, KMP(res.toString()));
            }
            out.println(ans);
        }
        out.close();
    }
 
    public static PrintWriter out;
    public static FastReader fs;
    public static final Random random = new Random();
 
    public static void ruffleSort(int[] a) {
        int n = a.length;
        for (int i = 0; i < n; ++i) {
            int oi = random.nextInt(n), tmp = a[oi];
            a[oi] = a[i];
            a[i] = tmp;
        }
        Arrays.sort(a);
    }
 
    public static class FastReader {
        private BufferedReader br;
        private StringTokenizer st = new StringTokenizer("");
 
        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }
 
        public FastReader(String file_name) throws FileNotFoundException {
            br = new BufferedReader(new InputStreamReader(new FileInputStream(new File(file_name))));
        }
 
        public String next() {
            while (!st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
 
        public int nextInt() {
            return Integer.parseInt(next());
        }
 
        public long nextLong() {
            return Long.parseLong(next());
        }
 
        public double nextDouble() {
            return Double.parseDouble(next());
        }
 
        public int[] readArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; ++i)
                a[i] = nextInt();
            return a;
        }
 
        public String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
}
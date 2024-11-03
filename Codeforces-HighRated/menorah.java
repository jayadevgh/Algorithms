// https://codeforces.com/contest/1615/problem/C

import java.io.*;
import java.util.*;
 
public class Main{
 
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;
 
        public FastReader()
        {
            br = new BufferedReader(
                new InputStreamReader(System.in));
        }
 
        String next()
        {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
 
        int nextInt() { return Integer.parseInt(next()); }
 
        long nextLong() { return Long.parseLong(next()); }
 
        double nextDouble()
        {
            return Double.parseDouble(next());
        }
 
        String nextLine()
        {
            String str = "";
            try {
                str = br.readLine();
            }
            catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
    
    
 
 
    
 
    
 
public static void main(String[] args) throws Exception {
 
 
    FastReader sc = new FastReader();
    
   int t=sc.nextInt();
 
   
  while(t-->0)
  {
      int n=sc.nextInt();
      String a=sc.next();
      String b=sc.next();
 
      char arr1[]=a.toCharArray();
      char arr2[]=b.toCharArray();
 
      int co1=0,co2=0;
 
      for(char c:arr1)
      {
          if(c=='1')
          co1++;
      }
 
      for(char c:arr2)
      {
          if(c=='1')
          co2++;
      }
      
      //System.out.println(co1+" "+co2);
 
      if((co1==0&&co2!=0)||((co1!=co2)&&n-co1+1!=co2))
      {
          System.out.println("-1");
      }
 
      else
      {
          int m1=Integer.MAX_VALUE,m2=Integer.MAX_VALUE,ans;
 
          if(co1==co2)
          {
              int diff=0;
              for(int i=0;i<n;i++)
              {
                  if(arr1[i]=='1'&&arr1[i]!=arr2[i])
                  {
                      diff++;
                  }
              }
              m1=diff*2;
          }
 
          if(n-co1+1==co2)
          {
              int idx=0;
              for(int i=0;i<n;i++)
              {
                  if(arr1[i]=='1'&&arr2[i]=='1')
                  {
                      idx=i;
                      break;
                  }
              }
 
              for(int i=0;i<n;i++)
              {
                  if(i!=idx)
                  {
                      arr1[i]=arr1[i]=='0'?'1':'0';
                  }
              }
 
              int diff=0;
              for(int i=0;i<n;i++)
              {
                  if(arr1[i]=='1'&&arr1[i]!=arr2[i])
                  {
                      diff++;
                  }
              }
               m2=diff*2+1;
 
          }
 
          ans=Math.min(m1,m2);
 
          System.out.println(ans);
 
 
 
      }
  }		
}
}
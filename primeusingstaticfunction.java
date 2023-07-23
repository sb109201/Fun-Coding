import java.util.*;
public class primeusingstaticfunction{
public static void prime1(int p){
 int i,c=0;
 for(i=2;i<13;i++){
 if(p%i==0)
 c++;
 }
 if(c==0){
   System.out.println("Prime");
 }
 else
     System.out.println("Not prime");
}
public static void main(String args[]){
 int p=13;
 prime1(p);
}
}

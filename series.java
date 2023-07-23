import java.util.*;
public class series{
public static void main(String args[]){
 double s=12,l;
 for(int i=1;i<100;i++){
  s=s+1/i;
 }
 System.out.printf("sum=%.3f",s);
}
}

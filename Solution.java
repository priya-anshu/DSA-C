import java.util.*;
class Solution{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n=sc.nextInt();
        int c=0, rem;
        for(int i=1; i<=n; i++){
            int temp = i;
            while (temp > 0) {
                rem = i%10;
                
                if (rem==4) {
                    c++;
                }
                temp = temp/10;
            }
        }
        System.out.println(c);
    }
}
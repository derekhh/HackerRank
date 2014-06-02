//prng-sequence-guessing.java
//PRNG Sequence Guessing
//Algorithms - Discrete Mathematics
//Author: derekhh

import java.util.Scanner;
import java.util.Random;

public class Solution {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        while(t-- > 0) {
            int mins = in.nextInt(), maxs = in.nextInt();
            int[] num = new int[10];
            for(int i = 0; i < 10; i++)
                num[i] = in.nextInt();
            int ds = 0;
            for(int s = mins; s <= maxs; s++) {
                boolean flag = true;
                Random r = new Random(s);
                for(int i = 0; i < 10; i++)
                    if (r.nextInt(1000) != num[i])
                        flag = false;
                if(flag) {
                    System.out.print(s + " ");
                    for(int i =0; i < 10; i++)
                        System.out.print(r.nextInt(1000) + " ");
                    System.out.println();
                }
            }
        }
    }
}
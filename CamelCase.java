import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class soln
{
    public static void main(String ar[])
    {
        Scanner in =new Scanner(System.in);
        String s=in.nextLine();
        int l=s.length();
        int c=1;
        for(int i=0;i<l;i++)
        {
            if(s.charAt(i)>='A' && s.charAt(i)<='Z')
                ++c;
        }
        System.out.println(c);
    }
}

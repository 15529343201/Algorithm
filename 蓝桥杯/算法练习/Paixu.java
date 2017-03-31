package lanqiao;

import java.util.Arrays;
import java.util.Scanner;

public class Paixu {
	public static void main(String[] args)
	{
		Scanner input=new Scanner(System.in);
		int[] a=new int[3];
		for(int i=0;i<3;i++)
		{
			a[i]=input.nextInt();
		}
		Arrays.sort(a);
		for(int i=2;i>=0;i--)
		{
			System.out.print(a[i]+" ");
		}
		input.close();
	}
}

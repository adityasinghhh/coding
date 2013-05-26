import java.io.*;
import java.util.*;
import java.math.BigInteger;

class eid
{
	static BigInteger zero = BigInteger.ZERO;
	static BigInteger one = BigInteger.ONE;

	static BigInteger gcd(BigInteger a, BigInteger b)
	{
		return b.gcd(a);
	}

	static BigInteger lcm(BigInteger a, BigInteger b)
	{
		BigInteger g = a.gcd(b);
		a = a.divide(g);
		return a.multiply(b);
	}

	public static void main(String[] args)
	{
		try
		{
			Scanner sc = new Scanner(System.in);

			int T = sc.nextInt(), zz=0;

			for(zz = 0; zz<T; ++zz)
			{
				int N = sc.nextInt();

				BigInteger l = one, g = one;
				for(int i=0; i<N; ++i)
				{
					int y = sc.nextInt();
					BigInteger x = new BigInteger(String.valueOf(y));
					g = l.gcd(x);
					l = l.divide(g);
					l = l.multiply(x);
				}

				System.out.println("Case " + (zz+1) + ": " + l);
			}
		}
		catch(Throwable e)
		{
			e.printStackTrace();
		}
	}
}

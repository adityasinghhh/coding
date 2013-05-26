import java.io.*;
import java.util.ArrayList;
import java.util.Random;
import java.math.BigInteger;

class insomb1
{
	static BigInteger mod(BigInteger a, BigInteger b, BigInteger c)
	{
		ArrayList<BigInteger> v = new ArrayList<BigInteger>();
		v.add(BigInteger.ONE);
		v.add(a);

		int i = 1;
		BigInteger k = BigInteger.ONE, temp = BigInteger.ZERO, two = new BigInteger("2");
		while(k.compareTo(b) <= 0)
		{
			temp = v.get(i).multiply(v.get(i));
			v.add(temp.mod(c));
			System.out.println("At i:" + i + ", we have: " + v.get(i));
			i++;
			k = k.multiply(two);
		}

		k = k.divide(two);
		i--;

		//printf("k:%d, i:%d\n", k, i);

		BigInteger x = BigInteger.ONE;
		while(b.compareTo(BigInteger.ZERO) != 0)
		{
			//	printf("%lld\n", x);
			if(b.compareTo(k) >= 0)
			{
				x = x.multiply(v.get(i));
				x = x.mod(c);
				b = b.subtract(k);
			}

			i--;
			k = k.divide(two);
		}

		//printf("%lld\n", x);

		System.out.println("Returning: " + x.divide(c));
		x = x.divide(c);
		return x;
	}

	static boolean prime(BigInteger p, int iterations)
	{
		if(p.compareTo(BigInteger.ONE) == 0)
			return false;

		int i;
		BigInteger a = p.subtract(new BigInteger("1"));
		BigInteger p1 = p.subtract(BigInteger.ONE);
		Random random = new Random();
		int r = 0;

		BigInteger comp = new BigInteger("123456789");

		int maxi = -1;
		if(p.compareTo(comp) < 0)
		{
			maxi = Integer.parseInt(p.toString())-1;
		}
		else
		{
			maxi = 123456789;
		}

		for(i = 0; i<iterations; i++)
		{
			r = random.nextInt(maxi); 

			a = new BigInteger(Integer.toString(r));

			if(mod(a, p1, p).compareTo(BigInteger.ONE) != 0)
				return false;
		}

		return true;
	}

	public static void main(String[] args)
	{
		try
		{
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

			BigInteger n = new BigInteger(br.readLine());

			if(prime(n, 1000))
				System.out.println("PRIME");
			else
				System.out.println("COMPOSITE");
		}
		catch(Throwable e)
		{
			e.printStackTrace();
		}

	}
}

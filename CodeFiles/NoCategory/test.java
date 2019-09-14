public class Optimal {
	public static int[] graycode(int n){
		int count = 0;
		int twoHatJ = 1;
		int[] g = new int[(int)Math.pow(2,n)];
		g[0] = 0;
		g[1] = 1;
		count = 2;
		for (int j = 1; j < n; j++)
		{
			twoHatJ = twoHatJ << 1;
			for (int i = 1; i <= twoHatJ; i++)
			{
g[count++] = twoHatJ | g[twoHatJ - i]; // HERE
}
}
return g;
}
public static void main(String[] args){
	int[] codes = graycode(4);
	for(int i = 0; i < codes.length; i++){
		System.out.println(codes[i]);
	}
}
}
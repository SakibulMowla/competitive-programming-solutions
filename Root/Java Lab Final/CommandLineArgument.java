public class CommandLineArgument {
    public static void main (String[] args) {
		int i, len;
		len = args.length;
        for (i=0; i<len; i++) {
            System.out.println(args[i]);
        }
    }
}

//CommandLineArgument
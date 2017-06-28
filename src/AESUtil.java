public class AESUtil {
	static { 
		System.load("/tmp/test/AESUtil.so"); 
		} 

	public native static String encrypt(String str, int len); 
	public native static String decrypt(String str, int len);

	public static void main(String[] args) {
		String enstr = "18600911335";
		String result = encrypt(enstr,enstr.length());
		System.out.println(encrypt(enstr,enstr.length()));
		System.out.println(decrypt(result,result.length()));

	}

}

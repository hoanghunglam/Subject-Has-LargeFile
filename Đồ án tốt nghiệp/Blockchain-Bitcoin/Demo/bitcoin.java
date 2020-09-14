import java.nio.charset.StandardCharsets;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class bitcoin {

/*     private static String bytesToHex(byte[] hash) {
        StringBuffer hexString = new StringBuffer();
        for (int i = 0; i < hash.length; i++) {
            String hex = Integer.toHexString(0xff & hash[i]);
            if (hex.length() == 1) {
                hexString.append('0');
            }
            hexString.append(hex);
        }
        return hexString.toString();
    } */

    public static String sha256(String input) {
        try {
            MessageDigest digest = MessageDigest.getInstance("SHA-256");
            byte[] encodeHash = digest.digest(input.getBytes(StandardCharsets.UTF_8));

            // convert the byte to hex format method 1
            StringBuffer sb = new StringBuffer();
            for (int i = 0; i < encodeHash.length; i++) {
                sb.append(Integer.toString((encodeHash[i] & 0xff) + 0x100, 16).substring(1));
            }
            return sb.toString();
        } catch (NoSuchAlgorithmException e) {
            return e.getMessage();
        }
    }

    public static void main(String[] args) {
        int difficulty = Integer.valueOf(args[0]);
        String target = "";
        for (int i = 0; i < difficulty; i++) {
            target = target + "0";
        }

        long start = System.currentTimeMillis();

        String hash = "";
        String timestamp = Long.toString(start);
        String data = "H?i chuy?n cho Lâm $200";
        int nonce = 0;

        while (!hash.startsWith(target)) {
            nonce = nonce + 1;
            hash = sha256(timestamp + data + nonce);
            System.err.println(nonce + "\t" + hash);
        }

        long stop = System.currentTimeMillis();
        System.err.println("==================================\nDifficulty Level: " + difficulty + " - Time elapsed: "
                + (stop - start) + "ms - Counter: " + nonce);
    }
}

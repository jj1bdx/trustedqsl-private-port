--- src/converter.cpp.FCS	2014-07-16 12:16:17.000000000 +0900
+++ src/converter.cpp	2014-07-16 12:16:40.000000000 +0900
@@ -88,7 +88,7 @@
 		optind++;
 		const char *ofile = (optind < argc) ? argv[optind] : "converted.tq7";
 		ofstream out;
-		out.open(ofile, ios::out|ios::trunc|ios::binary);
+		out.open(ofile, std::ios::out|std::ios::trunc|std::ios::binary);
 		if (!out.is_open())
 			throw myexc(string("Unable to open ") + ofile);
 		bool haveout = false;

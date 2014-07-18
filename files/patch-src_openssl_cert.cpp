--- src/openssl_cert.cpp.orig	2014-07-12 13:18:13.000000000 -0700
+++ src/openssl_cert.cpp	2014-07-17 16:36:04.000000000 -0700
@@ -4214,7 +4214,7 @@
 	for (ep = ellist.find("Cert"); ep != ellist.end(); ep++) {
 		if (ep->first != "Cert")
 			break;
-		pair<string, bool> rval = ep->second.getAttribute("serial");
+		pair<string, bool> rval = ep->second.get()->getAttribute("serial");
 		if (rval.second && strtol(rval.first.c_str(), NULL, 10) == serial) {
 			exists = true;
 			break;
@@ -4227,7 +4227,7 @@
 	se.setPretext(cs.getPretext() + "  ");
 	se.setElementName("status");
 	se.setText(status);
-	cs.addElement(se);
+	cs.addElement(shared_ptr<XMLElement>(&se));
 
 	cs.setAttribute("serial", sstr);
 	cs.setText("\n  ");
@@ -4235,7 +4235,7 @@
 	if (exists)
 		ellist.erase(ep);
 
-	sfile.addElement(cs);
+	sfile.addElement(shared_ptr<XMLElement>(&cs));
 	sfile.setText("\n");
 	return tqsl_dump_cert_status_data(sfile);
 }

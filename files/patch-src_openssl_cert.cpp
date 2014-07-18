--- src/openssl_cert.cpp.orig	2014-07-12 13:18:13.000000000 -0700
+++ src/openssl_cert.cpp	2014-07-17 16:36:04.000000000 -0700
@@ -4214,28 +4214,28 @@
 	for (ep = ellist.find("Cert"); ep != ellist.end(); ep++) {
 		if (ep->first != "Cert")
 			break;
-		pair<string, bool> rval = ep->second.getAttribute("serial");
+		pair<string, bool> rval = ep->second.get()->getAttribute("serial");
 		if (rval.second && strtol(rval.first.c_str(), NULL, 10) == serial) {
 			exists = true;
 			break;
 		}
 	}
 
-	XMLElement cs("Cert");
-	cs.setPretext("\n  ");
-	XMLElement se;
-	se.setPretext(cs.getPretext() + "  ");
-	se.setElementName("status");
-	se.setText(status);
-	cs.addElement(se);
+	shared_ptr<XMLElement> cs_p = make_shared<XMLElement>("Cert");
+	cs_p->setPretext("\n  ");
+	shared_ptr<XMLElement> se_p(new XMLElement);
+	se_p->setPretext(cs_p->getPretext() + "  ");
+	se_p->setElementName("status");
+	se_p->setText(status);
+	cs_p->addElement(se_p);
 
-	cs.setAttribute("serial", sstr);
-	cs.setText("\n  ");
+	cs_p->setAttribute("serial", sstr);
+	cs_p->setText("\n  ");
 
 	if (exists)
 		ellist.erase(ep);
 
-	sfile.addElement(cs);
+	sfile.addElement(cs_p);
 	sfile.setText("\n");
 	return tqsl_dump_cert_status_data(sfile);
 }

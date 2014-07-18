--- src/location.cpp.orig	2014-07-12 13:18:13.000000000 -0700
+++ src/location.cpp	2014-07-17 16:37:14.000000000 -0700
@@ -1957,7 +1957,7 @@
 			if (field.gabbi_name != "") {
 				// A field that may exist
 				XMLElement el;
-				if (ep->second.getFirstElement(field.gabbi_name, el)) {
+				if (ep->second.get()->getFirstElement(field.gabbi_name, el)) {
 					field.cdata = el.getText();
 					switch (field.input_type) {
                                                 case TQSL_LOCATION_FIELD_DDLIST:
@@ -2086,11 +2086,11 @@
 	for (ep = ellist.find("StationData"); ep != ellist.end(); ep++) {
 		if (ep->first != "StationData")
 			break;
-		pair<string, bool> rval = ep->second.getAttribute("name");
+		pair<string, bool> rval = ep->second.get()->getAttribute("name");
 		if (rval.second) {
 			TQSL_LOCATION *oldloc;
 			TQSL_LOCATION *newloc;
-			ep->second.getFirstElement("CALL", call);
+			ep->second.get()->getFirstElement("CALL", call);
 			for (size_t j = 0; j < calls.size(); j++) {
 				if (calls[j] == call.getText()) {
 					if (tqsl_getStationLocation(reinterpret_cast<tQSL_Location *>(&oldloc), rval.first.c_str())) { // Location doesn't exist
@@ -2125,7 +2125,7 @@
 	for (ep = ellist.find("StationData"); ep != ellist.end(); ep++) {
 		if (ep->first != "StationData")
 			break;
-		pair<string, bool> rval = ep->second.getAttribute("name");
+		pair<string, bool> rval = ep->second.get()->getAttribute("name");
 		if (rval.second && !strcasecmp(rval.first.c_str(), name)) {
 			ellist.erase(ep);
 			return tqsl_dump_station_data(sfile);
@@ -2158,7 +2158,7 @@
 	for (ep = ellist.find("StationData"); ep != ellist.end(); ep++) {
 		if (ep->first != "StationData")
 			break;
-		pair<string, bool> rval = ep->second.getAttribute("name");
+		pair<string, bool> rval = ep->second.get()->getAttribute("name");
 		if (rval.second && !strcasecmp(trim(rval.first).c_str(), trim(loc->name).c_str())) {
 			exists = true;
 			break;
@@ -2345,7 +2345,7 @@
 					break;
 			}
 			if (strcmp(fd.getText().c_str(), ""))
-				sd.addElement(fd);
+				sd.addElement(shared_ptr<XMLElement>(&fd));
 		}
 		int rval;
 		if (tqsl_hasNextStationLocationCapture(loc, &rval) || !rval)
@@ -2407,7 +2407,7 @@
 	for (ep = ellist.find("StationData"); ep != ellist.end(); ep++) {
 		if (ep->first != "StationData")
 			break;
-		pair<string, bool> rval = ep->second.getAttribute("name");
+		pair<string, bool> rval = ep->second.get()->getAttribute("name");
 		if (rval.second && !strcasecmp(rval.first.c_str(), loc->name.c_str())) {
 			exists = true;
 			break;
@@ -2428,7 +2428,7 @@
 	if (exists)
 		ellist.erase(ep);
 
-	sfile.addElement(sd);
+	sfile.addElement(shared_ptr<XMLElement>(&sd));
 	sfile.setText("\n");
 	return tqsl_dump_station_data(sfile);
 }

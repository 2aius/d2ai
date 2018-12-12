import os
import json

INDENT1 = "    "
INDENT2 = INDENT1 + INDENT1
INDENT3 = INDENT2 + INDENT1

AUTO_HEADER = "/*\n * THIS FILE IS AUTO-GENERATED - DO NOT EDIT\n */\n\n"

def toCapitals(id):
	n = ""
	for s in id.split("_"):
		n += s.capitalize()
	return n

def toAttributeName(id):
	n = ""
	isFirst = True
	for s in id.split("_"):
		if isFirst:
			n += s
			isFirst = False
		else:
			n += s.capitalize()
	return n

def toReference(type):
	prim = (type == "int") or (type == "long") or (type == "float") or (type == "double") or (type == "bool")
	if prim:
		return type
	else:
		return "const " + type + "&"

def toGetter(att):
	gtr = toReference(att["type"]) + " "
	if (att["type"] == "bool"):
		gtr += "is"
	else:
		gtr += "get"
	gtr += toCapitals(att["id"]) + "() const { return " + toAttributeName(att["id"]) + "; }"
	return gtr

def generateHeader(nm, cls):
	className = toCapitals(cls["id"])
	hdr = AUTO_HEADER
	hdr += "#pragma once\n"
	for i in cls["include_std"]:
		hdr += "\n#include <" + i + ">"
	for i in cls["include_h"]:
		hdr += '\n#include "' + nm + '_' + i + '.h"'
	hdr += "\n\nnamespace " + nm + " {\n\n"
	hdr += "// " + cls["doc"] + "\n"
	hdr += "class " + className + " final {\nprivate:\n\n"
	# attributes
	for a in cls["attributes"]:
		hdr += INDENT1 + a["type"] + " " + toAttributeName(a["id"]) + ";\n"
	hdr += "\npublic:\n\n"
	# static const NOT_DECODED
	hdr += INDENT1 + "static const " + className + " NOT_DECODED;\n\n"
	# ctor
	hdr += INDENT1 + "explicit " + className + "(\n"
	isFirst = True
	for a in cls["attributes"]:
		arg = toReference(a["type"]) + " " + toAttributeName(a["id"])
		if isFirst:
			hdr += INDENT2 + arg
			isFirst = False
		else:
			hdr += ",\n" + INDENT2 + arg
	hdr += ");\n"
	# getters
	for a in cls["attributes"]:
		hdr += "\n" + INDENT1 + "// " + a["doc"] + "\n"
		hdr += INDENT1 + toGetter(a) + "\n"
	hdr += "};\n\n"
	hdr += "} /* namespace " + nm + " */\n"
	return hdr

def generateCpp(nm, cls):
	className = toCapitals(cls["id"])
	cpp = AUTO_HEADER
	cpp += '#include "' + schema["namespace"] + '_' + cls["id"] + '.h"\n\n'
	cpp += "namespace " + nm + " {\n\n"
	# static const NOT_DECODED
	cpp += "const " + className + " " + className + "::NOT_DECODED{\n"
	isFirst = True
	for a in cls["attributes"]:
		if isFirst:
			isFirst = False
		else:
			cpp += ",\n"
		cpp += INDENT1 + ('""' if len(a["not_decoded"]) == 0 else a["not_decoded"]) 
	cpp += "\n};\n\n"
	# ctor
	cpp += className + "::" + className + "(\n"
	isFirst = True
	for a in cls["attributes"]:
		arg = toReference(a["type"]) + " " + toAttributeName(a["id"])
		if isFirst:
			cpp += INDENT2 + arg
			isFirst = False
		else:
			cpp += ",\n" + INDENT2 + arg
	cpp += ")\n"
	isFirst = True
	for a in cls["attributes"]:
		init = toAttributeName(a["id"]) + "(" + toAttributeName(a["id"]) + ")"
		if isFirst:
			cpp += INDENT1 + ": " + init
			isFirst = False
		else:
			cpp += ",\n" + INDENT1 + "  " + init
	cpp += " {\n}\n\n"
	cpp += "} /* namespace " + nm + " */\n"
	return cpp

# main
with open('schema.json') as f:
	schema = json.load(f)

dir_headers = "lib/headers/"
dir_cpp = "lib/cpp/"

for cls in schema["classes"]:

	file_h = dir_headers + schema["namespace"] + "_" + cls["id"] + ".h"
	if os.path.exists(file_h):
		os.remove(file_h)
	f = open(file_h, "x")
	f.write(generateHeader(schema["namespace"], cls))

	file_cpp = dir_cpp + schema["namespace"] + "_" + cls["id"] + ".cpp"
	if os.path.exists(file_cpp):
		os.remove(file_cpp)
	f = open(file_cpp, "x")
	f.write(generateCpp(schema["namespace"], cls))

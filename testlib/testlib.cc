/* libxmlccwrap - a C++ wrapper around libxml2
 * Copyright (C) 2002-2003 Juergen Rinas.
 * 
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#include <xmlccwrap/xmlccwrap.h>
#include <iostream>

using namespace xmlcc;
using namespace std;



void create_and_save_a_XMLTree()
{
  cout << "##### create_and_save_a_XMLTree ####" << endl;

  XMLTree tree;
  Element * root = new Element("root");
  tree.setRoot(root);

  root->add(Attribute("comment", "just a nice test"));

  Element * quoted = root->addElement("quotedchars");
  quoted->add
  (Attribute("lessthan", "<"));
  quoted->add
  (Attribute("geaterthan", ">"));
  quoted->add
  (Attribute("amp", "&"));
  quoted->add
  (Attribute("quot", "\""));
  quoted->addContent("< > & \"");

  Element * umlaute = root->addElement("umlaute");
  // this doesn't produce an error but is nonsense!
  //  umlaute->add(Attribute("umlaute-Latin1","‰ˆ¸ƒ÷‹ﬂ"));
  
  // this produces a runtime error "encoder error"
  //  umlaute->addContent("‰ˆ¸ƒ÷‹ﬂ");
  
  umlaute->add
  (Attribute("umlaute-converted", isolat1ToUTF8("‰ˆ¸ƒ÷‹ﬂ")));
  umlaute->addContent(isolat1ToUTF8("‰ˆ¸ƒ÷‹ﬂ"));

  cout << "# writing file test_defaultencoding.xml" << endl;
  tree.write("test_defaultencoding.xml");

  cout << "# writing file test_latin1encoding.xml" << endl;
  tree.setEncoding("ISO-8859-1");
  tree.write("test_latin1encoding.xml");
  
  
  cout << "# writing XMLTree as latin1 to stdout" << endl;
  cout << tree.writeBuffer() << endl;


  cout << "# writing file test_latin1encoding.xml.gz" << endl;
  tree.setCompression(9);
  tree.write("test_latin1encoding.xml.gz");


  /*
  cout << "writing crompressed tree to stdout" << endl;
  // not provided by libxml2 (2.4.24)
  cout << endl
       << "compresses output:" << endl
       << tree.write_buffer() << endl;
  */
}


void load_bad_XML_with_HTML_parser()
{
  cout << "##### load_bad_XML_with_HTML_parser ####" << endl;
 
  XMLTree tree2;
  
  cout << "# loading \"test_badquot.xml\" with html parser" << endl;
  tree2.readHTML("test_badquot.xml");
  cout << "# read OK" << endl;
  
  tree2.write("test_badquot_out.xml");
  cout << "# writing XMLTree to stdout" << endl;
  cout << tree2.writeBuffer() << endl;
  

  XMLTree tree3;
  Element * bodyel = *tree2.getRoot()->getElementList().begin();
  Element * newrootel = *bodyel->getElementList().begin();

  cout << "# creating a new tree without <html> and <body>" << endl;
  tree3.setRoot(new Element(*newrootel)); // we need to create a new tree

  tree3.write("test_badquot_out2.xml");
  cout << "# writing XMLTree to stdout" << endl;
  cout << tree3.writeBuffer() << endl;
}


void load_a_bad_xml_file()
{
  cout << "##### load_a_bad_xml_file ####" << endl;

  XMLTree badTree;
  badTree.read("test_badxml.xml");
  cout << "# badTree.getRoot()= " << badTree.getRoot() << endl;
  cout << "# badTree.getErrorString()= " << badTree.getErrorString() << endl;
  // cout << badTree.write_buffer() << endl; // this produces a segv
}


void read_file_and_display_encoding()
{
  cout << "##### read_file_and_display_encoding ####" << endl;

  XMLTree readDefaultTree;
  readDefaultTree.read("test_defaultencoding.xml");
  cout << "# readDefaultTree.getEncoding()=" << readDefaultTree.getEncoding() << endl;
  

  XMLTree readLatin1Tree;
  readLatin1Tree.read("test_latin1encoding.xml");
  cout << "# readLatin1Tree.getEncoding()=" << readLatin1Tree.getEncoding() << endl;
}


void copy_constructor_on_empty_tree()
{
  cout << "##### copy_constructor_on_empty_tree ####" << endl;
  
  XMLTree emptyTree;

  XMLTree newTree(emptyTree);
}


void test_xslt_class()
{
  cout << "##### test_xslt_class ####" << endl;

  XSLTTree xsltTree;
  cout << "# xsltTree.read " << xsltTree.read("test.xsl") << endl;
  
  
  XMLTree dataTree;
  dataTree.read("test_data.xml");
  
  cout << "# dataTree.xslt " << dataTree.xslt(xsltTree,"output1.xhtml") << endl;
  // ensure that reuse of xsltTree is possible
  cout << "# dataTree.xslt " << dataTree.xslt(xsltTree,"output2.xhtml") << endl;
}


int main()
{
  copy_constructor_on_empty_tree();  

  create_and_save_a_XMLTree();

  load_bad_XML_with_HTML_parser();

  load_a_bad_xml_file();
  
  read_file_and_display_encoding();
  
  test_xslt_class();
  
  cout << "##### end of "__FILE__" reached #####" << endl;

  return 0;
}

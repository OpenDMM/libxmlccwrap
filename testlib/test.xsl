<?xml version="1.0" encoding="ISO-8859-1"?>
<xsl:stylesheet version="1.0"
     xmlns:xsl="http://www.w3.org/1999/XSL/Transform">


  <xsl:output method="xml"
              doctype-public="-//W3C//DTD XHTML 1.1//EN"
	      doctype-system="http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd"
	      encoding="ISO-8859-1"
	      indent="yes"/>


  <xsl:template match="/">
    <html>
      <head>
        <title>testfile</title>
      </head>
      
      <body>
	<xsl:apply-templates select="root"/>
      </body>
    </html>
  </xsl:template>
  
    
  <xsl:template match="root">
    <table>
      <xsl:apply-templates select="data"/>
    </table>
  </xsl:template>


  <xsl:template match="data">
    <tr>
      <td>
        <xsl:value-of select="."/>
      </td>
    </tr>	
  </xsl:template>


</xsl:stylesheet>

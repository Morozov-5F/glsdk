<?xml version="1.0" encoding="UTF-8"?>
<xsl:transform xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
    xmlns:xs="http://www.w3.org/2001/XMLSchema"
    xmlns:xd="http://www.oxygenxml.com/ns/doc/xsl"
    exclude-result-prefixes="xs xd"
    xmlns:db="http://docbook.org/ns/docbook"
    version="2.0">
    
    <xsl:template match="node() | @*">
        <xsl:copy>
            <xsl:apply-templates select="@* | node()"/>
        </xsl:copy>
    </xsl:template>

    <xsl:template match="db:refmetainfo"/>
    
    <xsl:template match="db:refentry">
        <xsl:copy>
            <xsl:apply-templates select="@*"/>
            <xsl:if test="db:refmeta/db:refmetainfo">
                <db:info>
                    <xsl:apply-templates select="db:refmeta/db:refmetainfo/*"/>
                </db:info>
            </xsl:if>
            <xsl:apply-templates select="node()"/>
        </xsl:copy>
    </xsl:template>
    
    <xsl:template match="db:refsection/@xml:id"/>
    
</xsl:transform>
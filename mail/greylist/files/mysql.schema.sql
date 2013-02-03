CREATE TABLE IF NOT EXISTS `triplet` (
  `id` bigint(20) NOT NULL auto_increment,
  `client_address` varchar(40) default NULL,
  `sender` varchar(160) NOT NULL default '',
  `recipient` varchar(160) NOT NULL default '',
  `ip64` decimal(4,0) NOT NULL default '0',
  `ip32` decimal(4,0) NOT NULL default '0',
  `ip16` decimal(4,0) NOT NULL default '0',
  `ip8` decimal(4,0) NOT NULL default '0',
  `count` int(11) NOT NULL default '0',
  `uts` int(11) NOT NULL default '0',
  PRIMARY KEY  (`id`),
  KEY `sender` (`sender`,`recipient`,`ip64`,`ip32`,`ip16`,`ip8`)
) ENGINE=MyISAM ;

--
-- Table structure for table `network`
--
 
CREATE TABLE IF NOT EXISTS `network` (
  `address` varchar(16) NOT NULL default '',
  `comment` varchar(30) NOT NULL default '',
  PRIMARY KEY  (`address`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
 
-- --------------------------------------------------------
 
--
-- Table structure for table `pattern`
--
 
CREATE TABLE IF NOT EXISTS `pattern` (
  `expression` varchar(200) NOT NULL default '',
  `comment` varchar(30) NOT NULL default '',
  PRIMARY KEY  (`expression`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
 
-- --------------------------------------------------------
 
--
-- Table structure for table `recipient`
--
 
CREATE TABLE IF NOT EXISTS `recipient` (
  `address` varchar(200) NOT NULL default '',
  `comment` varchar(30) NOT NULL default '',
  PRIMARY KEY  (`address`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
 
-- --------------------------------------------------------
 
--
-- Table structure for table `sender`
--
 
CREATE TABLE IF NOT EXISTS `sender` (
  `address` varchar(200) NOT NULL default '',
  `comment` varchar(30) NOT NULL default '',
  PRIMARY KEY  (`address`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

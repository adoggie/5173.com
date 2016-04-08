/*==============================================================*/
/* DBMS name:      PostgreSQL 7                                 */
/* Created on:     2010/5/26 16:07:21                           */
/*==============================================================*/


drop index idx_rdserver_mac;

drop table rdserver;

drop index idx_rdserver_mac2;

drop table rdserver_connect_status;

drop index idx_rdserver_mac3;

drop table rdserver_status;

/*==============================================================*/
/* Table: rdserver                                              */
/*==============================================================*/
create table rdserver (
mac                  CHAR(20)             not null,
ip                   VARCHAR(20)          not null,
port                 INT4                 not null,
qos                  INT4                 not null,
qos_tick             INT4                 not null,
status_tick          INT4                 not null,
conn_num             INT2                 not null,
hostname             VARCHAR(20)          not null,
status_interval      INT4                 not null,
vendor               CHAR(40)             not null,
constraint PK_RDSERVER primary key (mac)
);

comment on table rdserver is
'转发服务器列表';

comment on column rdserver.mac is
'网卡地址';

comment on column rdserver.ip is
'公网地址';

comment on column rdserver.port is
'服务器端口';

comment on column rdserver.qos is
'ping带宽质量';

comment on column rdserver.qos_tick is
'记录时间';

comment on column rdserver.status_tick is
'rdserver同步时间';

comment on column rdserver.conn_num is
'当前连接数量';

comment on column rdserver.hostname is
'主机名';

comment on column rdserver.status_interval is
'状态上报时间间隔';

comment on column rdserver.vendor is
'发布者';

/*==============================================================*/
/* Index: idx_rdserver_mac                                      */
/*==============================================================*/
create unique index idx_rdserver_mac on rdserver (
mac
);

/*==============================================================*/
/* Table: rdserver_connect_status                               */
/*==============================================================*/
create table rdserver_connect_status (
mac                  CHAR(20)             not null,
ip                   VARCHAR(20)          not null,
port                 INT4                 not null,
time_tick            INT4                 not null,
client_ip            INT4                 not null,
game_id              INT2                 not null,
trade_no             VARCHAR(30)          not null,
status               INT2                 not null,
constraint PK_RDSERVER_CONNECT_STATUS primary key (mac)
);

comment on table rdserver_connect_status is
'转发服务器列表';

comment on column rdserver_connect_status.mac is
'代理服务器网卡';

comment on column rdserver_connect_status.ip is
'代理服务器地址';

comment on column rdserver_connect_status.port is
'代理服务器端口';

comment on column rdserver_connect_status.time_tick is
'时间';

comment on column rdserver_connect_status.client_ip is
'客户机地址';

comment on column rdserver_connect_status.game_id is
'游戏编号';

comment on column rdserver_connect_status.trade_no is
'交易单号';

comment on column rdserver_connect_status.status is
'0 - 建立连接; 1 - 断开连接';

/*==============================================================*/
/* Index: idx_rdserver_mac2                                     */
/*==============================================================*/
create unique index idx_rdserver_mac2 on rdserver_connect_status (
mac
);

/*==============================================================*/
/* Table: rdserver_status                                       */
/*==============================================================*/
create table rdserver_status (
mac                  CHAR(20)             not null,
ip                   VARCHAR(20)          not null,
port                 INT4                 not null,
status_tick          INT4                 not null,
conn_num             INT2                 not null,
status_interval      INT4                 not null,
constraint PK_RDSERVER_STATUS primary key (mac)
);

comment on table rdserver_status is
'转发服务器列表';

comment on column rdserver_status.mac is
'网卡地址';

comment on column rdserver_status.ip is
'公网地址';

comment on column rdserver_status.port is
'转发服务端口';

comment on column rdserver_status.status_tick is
'rdserver同步时间';

comment on column rdserver_status.conn_num is
'当前连接数量';

comment on column rdserver_status.status_interval is
'状态上报时间间隔';

/*==============================================================*/
/* Index: idx_rdserver_mac3                                     */
/*==============================================================*/
create unique index idx_rdserver_mac3 on rdserver_status (
mac
);

